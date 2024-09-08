#include "../headers/trx_handler.hpp"

enum enTrx
{
  ListOfBalances = 1,
  Deposit = 2,
  Withdraw = 3,
  MainMenu = 4
};

uint16_t Trx_Menu_Handler(uint16_t Picker)
{
  vector <string> vRecs = LoadRecordsFromFile("Recs");
  
  switch (Picker) {
  case (enTrx::ListOfBalances):
    DisplayBalancesTable(vRecs);
    break;
  case (enTrx::Deposit):
    break;
  case (enTrx::Withdraw):
    break;
  case (enTrx::MainMenu):
    OnBeginPlay();
    break;
  }
  
  return (Picker);
}
