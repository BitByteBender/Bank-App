#include "../headers/core.hpp"
#include "../headers/library/displayLib.hpp"
#include "../headers/library/inputLib.hpp"

void OnBeginPlay(void)
{
  uint16_t Num = 0;
  
  do {
    displayLib::MainMenuScreen("\t    Main Menu Screen");
    Num = std::stoi(inputs::PromptReader("Choose from the list: "));
    if (Num >= 1 && Num <= 7)
      Functionalities(Num);
  } while (Num != 7);
}

void TriggerTrxMenu(void)
{
  uint16_t Num = 0;
  
  do {
    displayLib::TransactionsScreen("\tTransactions Menu Screen");
    Num = std::stoi(inputs::PromptReader("Choose from the list: "));
    if (Num >= 1 && Num <= 4)
      Trx_Menu_Handler(Num);
  } while (Num != 4);
}

void OnExit(void)
{
  exit(0);
}
