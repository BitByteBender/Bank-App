#include "../headers/trx_handler.hpp"
#include "../headers/library/inputLib.hpp"

enum enTrx
{
  ListOfBalances = 1,
  Deposit = 2,
  Withdraw = 3,
  MainMenu = 4
};

void Trx_Menu_Handler(uint16_t Picker)
{
  vector <string> vRecs = LoadRecordsFromFile("Recs");
  
  switch (Picker) {
  case (enTrx::ListOfBalances):
    DisplayBalancesTable(vRecs);
    char(inputs::PromptReader("\nPress [0] to get back to transaction menu... ")[0]);
    break;
  case (enTrx::Deposit):
    break;
  case (enTrx::Withdraw):
    break;
  case (enTrx::MainMenu):
    OnBeginPlay();
    break;
  }
}
