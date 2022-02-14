use std::convert::TryInto;
use solana_program::program_error::ProgramError;
use crate::error::MarketError::InvalidInstruction;

pub enum MarketInstruction {
    /// Accounts expected:
    ///
    /// 0. `[signer]` The account of the game owner
    /// 1. `[writable]` The game owner's token account that will be controlled by market
    /// 2. `[]` The token program
    InitMarket,

    /// Accounts expected:
    ///
    /// 0. `[signer]` The account of the token buyer
    /// 1. `[writable]` The token account owner by game owner
    /// 2. `[writable]` The token account owner by buyer to receive game tokens
    /// 3. `[]` The token program
    /// 4. `[]` The PDA account
    BuyToken {
        amount: u64
    },

    SellToken {
        amount: u64
    },
}

impl MarketInstruction {

    pub fn unpack(input: &[u8]) -> Result<Self, ProgramError> {
        let (tag, rest) = input.split_first().ok_or(InvalidInstruction)?;

        Ok(match tag {
            0 => Self::InitMarket,
            1 => Self::BuyToken {
                amount: Self::unpack_amount(rest)?,
            },
            2 => Self::SellToken {
                amount: Self::unpack_amount(rest)?,
            },
            _ => return Err(InvalidInstruction.into()),
        })
    }

    fn unpack_amount(input: &[u8]) -> Result<u64, ProgramError> {
        let amount = input
            .get(..8)
            .and_then(|slice| slice.try_into().ok())
            .map(u64::from_le_bytes)
            .ok_or(InvalidInstruction)?;
        Ok(amount)
    }
}