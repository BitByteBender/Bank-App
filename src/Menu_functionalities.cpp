#include "../headers/core.hpp"
#include "../headers/library/inputLib.hpp"
#include "../headers/library/displayLib.hpp"
#include "../headers/library/strLib.hpp"
#include "../headers/library/handlers.hpp"
#include "../headers/crud.hpp"

enum enMenu
{
  ShowClientList = 1,
  AddNewClient = 2,
  DeleteClient = 3,
  UpdateClient = 4,
  FindClient = 5,
  Transactions = 6,
  UserManger = 7
  // Logout = 8
};

uint16_t Functionalities(uint16_t Picker)
{
  vector <string> vRecs;
  vector <stClient> vClients;
  string fname = "Recs";
  string AccNum = "";
  
  switch (Picker) {
  case (enMenu::ShowClientList):
    return (PrintClientList(vRecs, fname));
  case (enMenu::AddNewClient):
    return (InsertNewClient(vClients, vRecs, fname));
  case (enMenu::DeleteClient):
    AccNum = inputs::PromptReader("Enter AccountNumber: ");
    vRecs = DeleteClientRec(AccNum, vRecs, fname);
    return (std::stoi(inputs::PromptReader("\nPress [0] to get back to Main Menu ")));
  case (enMenu::UpdateClient):
    AccNum = inputs::PromptReader("Enter AccountNumber: ");
    UpdateClientRec(AccNum, vRecs, fname);
    return (std::stoi(inputs::PromptReader("\nPress [0] to get back to Main Menu ")));
  case (enMenu::FindClient):
    AccNum = inputs::PromptReader("Enter AccountNumber: ");
    FindRecord(AccNum, vRecs, fname);
    return (std::stoi(inputs::PromptReader("\nPress [0] to get back to Main Menu ")));
  case (enMenu::Transactions):
    TriggerTrxMenu();
    break;
  case (enMenu::UserManger):
    /* User Manager Func Here */
    break;
  /*case (enMenu::Logout):
    // This needs to be change to get back to login screen
    OnExit();
    break;*/
  }
  
  return (Picker);
}
