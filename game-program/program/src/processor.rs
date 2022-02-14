use solana_program::{
    account_info::{next_account_info, AccountInfo},
    entrypoint::ProgramResult,
    program_error::ProgramError,
    msg, pubkey::Pubkey,
    program::{invoke, invoke_signed}
};

use crate::{instruction::MarketInstruction};

pub struct Processor;

impl Processor {
    pub fn process(program_id: &Pubkey, accounts: &[AccountInfo], instruction_data: &[u8]) -> ProgramResult {
        let instruction = MarketInstruction::unpack(instruction_data)?;

        match instruction {
            MarketInstruction::InitMarket => {
                msg!("Instruction: InitMarket");
                Self::process_init_market(accounts, program_id)
            }
            MarketInstruction::BuyToken { amount } => {
                msg!("Instruction: BuyToken");
                Self::process_buy_token(accounts, amount, program_id)
            }
            _ => Ok(())
        }
    }

    fn process_init_market(
        accounts: &[AccountInfo],
        program_id: &Pubkey,
    ) -> ProgramResult {
        let account_info_iter = &mut accounts.iter();
        let game_owner = next_account_info(account_info_iter)?;

        if !game_owner.is_signer {
            return Err(ProgramError::MissingRequiredSignature);
        }

        let game_token_account = next_account_info(account_info_iter)?;

        if *game_token_account.owner != spl_token::id() {
            return Err(ProgramError::IncorrectProgramId);
        }

        let (pda, _bump_seed) = Pubkey::find_program_address(&[b"flightace"], program_id);

        let token_program = next_account_info(account_info_iter)?;
        let owner_change_ix = spl_token::instruction::set_authority(
            token_program.key,
            game_token_account.key,
            Some(&pda),
            spl_token::instruction::AuthorityType::AccountOwner,
            game_owner.key,
            &[&game_owner.key],
        )?;

        msg!("Calling the token program to transfer token account ownership...");
        invoke(
            &owner_change_ix,
            &[
                game_token_account.clone(),
                game_owner.clone(),
                token_program.clone(),
            ],
        )?;

        Ok(())
    }

    fn process_buy_token(
        accounts: &[AccountInfo],
        amount_requested: u64,
        program_id: &Pubkey,
    ) -> ProgramResult {
        let account_info_iter = &mut accounts.iter();
        let buyer = next_account_info(account_info_iter)?;

        if !buyer.is_signer {
            return Err(ProgramError::MissingRequiredSignature);
        }

        let game_token_account = next_account_info(account_info_iter)?;

        // invoke(
        //     &system_instruction::transfer(buyer.key, game_token_account.key, amount_requested / 10),
        //     &[buyer.clone(), game_token_account.clone()],
        // )?;
        // msg!("transfer {} lamports from {:?} to {:?}: done", amount_requested / 10, buyer.key, game_token_account.key);

        let buyer_token_to_receive_account = next_account_info(account_info_iter)?;
        let (pda, bump_seed) = Pubkey::find_program_address(&[b"flightace"], program_id);
        let token_program = next_account_info(account_info_iter)?;
        let pda_account = next_account_info(account_info_iter)?;

        let transfer_to_buyer_ix = spl_token::instruction::transfer(
            token_program.key,
            game_token_account.key,
            buyer_token_to_receive_account.key,
            &pda,
            &[&pda],
            amount_requested,
        )?;
        msg!("Calling the token program to transfer tokens to buyer");


        invoke_signed(
            &transfer_to_buyer_ix,
            &[
                game_token_account.clone(),
                buyer_token_to_receive_account.clone(),
                pda_account.clone(),
                token_program.clone(),
            ],
            &[&[&b"flightace"[..], &[bump_seed]]],
        )?;

        Ok(())
    }
}