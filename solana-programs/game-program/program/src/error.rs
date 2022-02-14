use thiserror::Error;
use solana_program::program_error::ProgramError;

#[derive(Error, Debug, Copy, Clone)]
pub enum MarketError {
    /// Invalid instruction
    #[error("Invalid Instruction")]
    InvalidInstruction,
    /// Invalid instruction
    #[error("Non Rent-exempt")]
    NotRentExempt,
}

impl From<MarketError> for ProgramError {
    fn from(e: MarketError) -> Self {
        ProgramError::Custom(e as u32)
    }
}