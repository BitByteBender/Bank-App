#include "../headers/core.hpp"
#include "../headers/library/inputLib.hpp"
#include "../headers/library/displayLib.hpp"

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
    return (InsertNewClient(vClients, vRecs, fname));
  case (enMenu::FindClient):
    return (FindRecord(vRecs, fname));
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
  return (std::stoi(inputs::PromptReader("\nPress [0] to get back to Main Menu ")));
}

uint16_t InsertNewClient(vector <stClient> &vClients, vector <string> &vRecs, string fname)
{
  vClients = SaveRecords();
  vRecs = SaveRecords(vClients);
  vRecs = LoadRecordsFromFile(fname);

  return (std::stoi(inputs::PromptReader("\nPress [0] to get back to Main Menu ")));
}

string GetSingleRecord(string &AccNum, vector <string> &vRecs, string fname)
{
  vRecs = LoadRecordsFromFile(fname);
  short pos = 0;
  
  if (!vRecs.empty()) {
    for (const string &r:vRecs) {
      pos = r.find("#/\\#");
      if (r.substr(0, pos) == AccNum)
	return (r);
    }
  }
  return ("None");
}

bool CheckRecord(string &AccNum, vector <string> &vRecs, string fname)
{
  return (GetSingleRecord(AccNum, vRecs, fname) != "None");
}

uint16_t FindRecord(vector <string> &vRecs, string fname)
{
  string AccNum = inputs::PromptReader("Enter AccountNumber: ");
  vector <string> vCntr;
  
  if (CheckRecord(AccNum, vRecs, fname)) {
    vCntr = splitLine(GetSingleRecord(AccNum, vRecs, fname), "#/\\#");
    displayLib::DisplaySingleRecord(LineToRecord(vCntr));
  } else
    cout<<"Client with Account Number (" + AccNum + ") is Not Found!\n";
  
  return (std::stoi(inputs::PromptReader("\nPress [0] to get back to Main Menu ")));
}

/*
void DeleteClient(vector <string> &vRecs, vector <stClient> &vClients, string fname)
{
  
  vClients = SaveRecords();
  vRecs = SaveRecords(vClients);
  vRecs = LoadRecordsFromFile(fname);
}
*/
