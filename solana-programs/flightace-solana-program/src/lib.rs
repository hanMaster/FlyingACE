use borsh::{BorshDeserialize, BorshSerialize};
use solana_program::{
    account_info::{next_account_info, AccountInfo},
    entrypoint,
    entrypoint::ProgramResult,
    msg,
    program_error::ProgramError,
    pubkey::Pubkey,
};

#[derive(BorshSerialize, BorshDeserialize, Debug)]
pub struct FlightACEAccount {
    pub score: u64,
}

entrypoint!(process_instruction);

pub fn process_instruction(
    program_id: &Pubkey,
    accounts: &[AccountInfo],
    instruction_data: &[u8],
) -> ProgramResult {
    msg!("FlightACE score program entrypoint");

    let accounts_iter = &mut accounts.iter();
    let account = next_account_info(accounts_iter)?;

    // The account must be owned by the program in order to modify its data
    if account.owner != program_id {
        msg!("FlightACE account does not have the correct program id");
        return Err(ProgramError::IncorrectProgramId);
    }

    let mut flightace_account = FlightACEAccount::try_from_slice(&account.data.borrow())?;

    let score = instruction_data
        .get(..8)
        .and_then(|slice| slice.try_into().ok())
        .map(u64::from_le_bytes)
        .ok_or(ProgramError::InvalidInstructionData)?;


    flightace_account.score = score;

    flightace_account.serialize(&mut &mut account.data.borrow_mut()[..])?;

    msg!("FlightACE: score:{}", flightace_account.score);

    Ok(())
}

#[cfg(test)]
mod test {
    use super::*;
    use solana_program::clock::Epoch;

    #[test]
    fn test_sanity() {
        let program_id = Pubkey::default();
        let key = Pubkey::default();
        let mut lamports = 0;
        let mut data = FlightACEAccount {
            score: 0
        }.try_to_vec().unwrap();
        let owner = Pubkey::default();
        let account = AccountInfo::new(
            &key,
            false,
            true,
            &mut lamports,
            &mut data,
            &owner,
            false,
            Epoch::default(),
        );
        let amount: u64 = 5900;
        let instruction_data = &amount.to_le_bytes() as &[u8];
        let accounts = vec![account];

        assert_eq!(FlightACEAccount::try_from_slice(&accounts[0].data.borrow()).unwrap().score, 0);

        process_instruction(&program_id, &accounts, &instruction_data).unwrap();
        assert_eq!(FlightACEAccount::try_from_slice(&accounts[0].data.borrow()).unwrap().score, 5900);
    }

    #[test]
    fn decode_data() {
        let data: &[u8] = &[208, 69, 68, 0, 0, 96, 0, 0];
        let score = data
            .get(..8)
            .and_then(|slice| slice.try_into().ok())
            .map(u64::from_le_bytes)
            .ok_or(ProgramError::InvalidInstructionData).unwrap();
        println!("Data: {}", score);
    }
}

