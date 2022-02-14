import { readFileSync } from "fs"
import { ASSOCIATED_TOKEN_PROGRAM_ID, Token, TOKEN_PROGRAM_ID } from "@solana/spl-token"
import {
  Connection,
  Keypair,
  PublicKey,
  sendAndConfirmTransaction, SystemProgram,
  Transaction,
  TransactionInstruction,
} from "@solana/web3.js"
import lo from "buffer-layout"
import BN from "bn.js"

function readKeypairFromPath(path: string): Keypair {
  const data = JSON.parse(readFileSync(path, "utf-8"))
  return Keypair.fromSecretKey(Buffer.from(data))
}

async function createAssociatedTokenAccount(
  connection: Connection,
  mint: PublicKey,
  wallet: Keypair
): Promise<PublicKey> {
  const associatedTokenAddress = await Token.getAssociatedTokenAddress(
    ASSOCIATED_TOKEN_PROGRAM_ID,
    TOKEN_PROGRAM_ID,
    mint,
    wallet.publicKey
  )
  if (await connection.getAccountInfo(associatedTokenAddress)) {
    // associated token account is already created
    return associatedTokenAddress
  }

  const tokenClient = new Token(connection, mint, TOKEN_PROGRAM_ID, wallet)
  console.log("create associated token account for", wallet.publicKey.toBase58())
  return await tokenClient.createAssociatedTokenAccount(wallet.publicKey)
}

async function main() {
  const connection = new Connection("http://localhost:8899", "confirmed")
  const mint = new PublicKey("CZyEKArwVYSKkv9im3grGNXmggbPfS8YGUovBnzoKQ4s")
  const programKeypair = readKeypairFromPath(__dirname + "/../localnet/program.json")
  const gameOwnerKeypair = readKeypairFromPath(__dirname + "/../localnet/game-owner.json")
  const gamerKeypair = readKeypairFromPath(__dirname + "/../localnet/gamer.json")
  const gameOwnerTokenPubkey = await createAssociatedTokenAccount(connection, mint, gameOwnerKeypair)
  const gamerTokenPubkey = await createAssociatedTokenAccount(connection, mint, gamerKeypair)

  console.log(`gamerTokenPubkey: ${gamerTokenPubkey.toBase58()}`)

  const amount = Buffer.alloc(8) // 5 SPL
  lo.ns64("value").encode(new BN("5000000000"), amount)

  // Init market
  const initMarketIx = new TransactionInstruction({
    keys: [
      { pubkey: gameOwnerKeypair.publicKey, isSigner: true, isWritable: true },
      { pubkey: gameOwnerTokenPubkey, isSigner: false, isWritable: true },
      { pubkey: TOKEN_PROGRAM_ID, isSigner: false, isWritable: false },
    ],
    programId: programKeypair.publicKey,
    data: Buffer.of(0),
  })
  const resInit = await sendAndConfirmTransaction(connection, new Transaction().add(initMarketIx), [
    gameOwnerKeypair,
  ])
  console.log("init tx", resInit)

  // Buy tokens

  // // encode 0.5 SOL as an input_data
  // const data = Buffer.alloc(8)
  // lo.ns64("value").encode(new BN("500000000"), data)
  //
  // const ix = new TransactionInstruction({
  //   keys: [
  //     { pubkey: gamerKeypair.publicKey, isSigner: true, isWritable: true },
  //     { pubkey: gameOwnerTokenPubkey, isSigner: false, isWritable: true },
  //     { pubkey: SystemProgram.programId, isSigner: false, isWritable: false },
  //   ],
  //   programId: programKeypair.publicKey,
  //   data: data,
  // })
  // const res = await sendAndConfirmTransaction(connection, new Transaction().add(ix), [gamerKeypair])
  // console.log(`lamports sent: ${res}`)

// ==================================================================
  const PDA = await PublicKey.findProgramAddress(
      [Buffer.from("flightace")],
      programKeypair.publicKey
  );

  const transferIx = new TransactionInstruction({
    keys: [
      { pubkey: gamerKeypair.publicKey, isSigner: true, isWritable: false },
      { pubkey: gameOwnerTokenPubkey, isSigner: false, isWritable: true },
      { pubkey: gamerTokenPubkey, isSigner: false, isWritable: true },
      { pubkey: TOKEN_PROGRAM_ID, isSigner: false, isWritable: false },
      { pubkey: PDA[0], isSigner: false, isWritable: false },
    ],
    programId: programKeypair.publicKey,
    data: Buffer.of(1, ...amount),
  })
  const transferRes = await sendAndConfirmTransaction(
    connection,
    new Transaction().add(transferIx),
    [gamerKeypair]
  )
  console.log("transfer tx", transferRes)
}

main()
  .then(() => process.exit(0))
  .catch((err) => console.error(err))
