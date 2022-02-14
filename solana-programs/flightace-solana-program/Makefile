validator:
	solana-test-validator -r --ledger localnet/ledger

deploy:
	cargo build-bpf
	solana program deploy target/deploy/flightace.so -u localhost --program-id localnet/program.json

init:
	cd account/; ./node_modules/ node index.js

state:
	solana account 9ZJd6BhBrUetpM2r9MbxQzoiWN7dTzU3fauEZftGyH9v

# programId 5keeyTrvUnZD2ZCxViAhfbFfZwNFuaCKtgKydoTosAdc
# flightace account: 9ZJd6BhBrUetpM2r9MbxQzoiWN7dTzU3fauEZftGyH9v