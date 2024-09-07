#include "../headers/core.hpp"
#include "../headers/library/inputLib.hpp"

enum enMenu
{
  ShowClientList = 1,
  AddNewClient = 2,
  UpdateClient = 3,
  DeleteClient = 4,
  FindClient = 5,
  Exit = 6
};

uint16_t Functionalities(uint16_t Picker)
{
  vector <string> vRecs;
  vector <stClient> vClients;
  string fname = "Recs";
  
  switch (Picker) {
  case (enMenu::ShowClientList):
    return (PrintClientList(vRecs, fname));
  case (enMenu::AddNewClient):
    InsertNewClient(vClients, vRecs, fname);
    break;
  case (enMenu::Exit):
    OnExit();
    break;
  }
  
  return (Picker);
}

uint16_t PrintClientList(vector <string> &vRecs, string fname)
{
  vRecs = LoadRecordsFromFile(fname);
  DisplayClientsList(vRecs);
  return (std::stoi(inputs::PromptReader("Press [0] to get back to Main Menu")));
}

void InsertNewClient(vector <stClient> &vClients, vector <string> &vRecs, string fname)
{
  vClients = SaveRecords();
  vRecs = SaveRecords(vClients);
  vRecs = LoadRecordsFromFile(fname);
}
