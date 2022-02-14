.PHONY: localnet client

validator:
	solana-test-validator -r --ledger localnet/ledger

init:
	solana airdrop 1 CD6To88A4KrApbnDUkHrwpjMY5ufgPpVQzm9rRX5d3ro -u localhost
	solana airdrop 1 CD6To88A4KrApbnDUkHrwpjMY5ufgPpVQzm9rRX5d3ro -u localhost
	solana airdrop 1 9C8ARBpAqcmoDfqZTDtvB1JgZC7gjvcq48xRJoR7Wpeq -u localhost
	spl-token create-token localnet/token.json
	spl-token create-account CZyEKArwVYSKkv9im3grGNXmggbPfS8YGUovBnzoKQ4s --owner localnet/game-owner.json
	spl-token mint CZyEKArwVYSKkv9im3grGNXmggbPfS8YGUovBnzoKQ4s 300 G6GTsFAnYP1PaNc1g36SF4iuEiosfTZZCWWdnCNxxA8d # mint to game-owner 300 SPL

state:
	solana balance CD6To88A4KrApbnDUkHrwpjMY5ufgPpVQzm9rRX5d3ro # game-owner
	spl-token account-info --address G6GTsFAnYP1PaNc1g36SF4iuEiosfTZZCWWdnCNxxA8d # game-owner
	solana balance 6h21yZr5Ezvv764EzhpdqMAkVxmj99JEGX5Tvrr8AyBD # gamer
	spl-token account-info --address AoebUr1dtpy4Zho5qFdhjrguZMZGHqErqFPhiWLVMgmA # gamer

deploy:
	cd program; cargo build-bpf
	solana program deploy program/target/deploy/game_program.so -u localhost --program-id localnet/program.json

client:
	cd client/; ./node_modules/.bin/ts-node main.ts
