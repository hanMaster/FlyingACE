const os = require('os');
const fs = require('mz/fs');
const path = require('path');
const yaml = require('yaml');
const web3 = require('@solana/web3.js');
const borsh = require('borsh');
const {readFileSync} = require("fs");

let connection;
let payer;
let programId;
let flightacePubkey;

const getRpcUrl = async () => {
    return 'http://localhost:8899';
}

const createKeypairFromFile = (filePath) => {
    const secretKeyString = fs.readFileSync(filePath, {encoding: 'utf8'});
    const secretKey = Uint8Array.from(JSON.parse(secretKeyString));
    return web3.Keypair.fromSecretKey(secretKey);
}

/**
 * The state of a program
 */
class FlightACEAccount {
    score = 0;

    constructor(score) {
        if (score) {
            this.score = score;
        }
    }
}

/**
 * Borsh schema definition
 */
const FlightACESchema = new Map([
    [
        FlightACEAccount,
        {
            kind: 'struct',
            fields: [
                ['score', 'u64'],
            ]
        }
    ],
]);

const FLIGHT_SIZE = borsh.serialize(
    FlightACESchema,
    new FlightACEAccount(),
).length;

const establishConnection = async () => {
    const rpcUrl = await getRpcUrl();
    connection = new web3.Connection(rpcUrl, 'confirmed');
    const version = await connection.getVersion();
    console.log('Connection to cluster established:', rpcUrl, version);
}

const createAccount = async () => {

    try {
        const programKeypair = await createKeypairFromFile(__dirname + "/../localnet/program.json");
        programId = programKeypair.publicKey;
        console.log(`programId: ${programId.toBase58()}`);
    } catch (err) {
        const errMsg = err.message;
        throw new Error(
            `Failed to read program keypair at '${__dirname + "/../localnet/program.json"}' due to error: ${errMsg}. Program may need to be deployed`,
        );
    }

    await establishConnection();
    payer = createKeypairFromFile(__dirname + "/../localnet/gamer.json");

    console.log(`payer: ${payer.publicKey.toBase58()}`)

    // Derive the address (public key) of a gamer account from the program so that it's easy to find later.
    const FLIGHT_SEED = 'flightace';
    flightacePubkey = await web3.PublicKey.createWithSeed(
        payer.publicKey,
        FLIGHT_SEED,
        programId,
    );

    // Check if the greeting account has already been created
    const flightaceAccount = await connection.getAccountInfo(flightacePubkey);
    if (flightaceAccount === null) {
        console.log(`Creating flightace account: ${flightacePubkey.toBase58()}`);
        const lamports = await connection.getMinimumBalanceForRentExemption(FLIGHT_SIZE);

        const transaction = new web3.Transaction().add(
            web3.SystemProgram.createAccountWithSeed({
                fromPubkey: payer.publicKey,
                basePubkey: payer.publicKey,
                seed: FLIGHT_SEED,
                newAccountPubkey: flightacePubkey,
                lamports,
                space: FLIGHT_SIZE,
                programId,
            }),
        );
        await web3.sendAndConfirmTransaction(connection, transaction, [payer]);
    }
}

const run = async () => {
    await createAccount()
}

run()
