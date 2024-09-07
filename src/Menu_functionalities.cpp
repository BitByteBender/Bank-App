#include "../headers/core.hpp"
#include "../headers/library/inputLib.hpp"
#include "../headers/library/displayLib.hpp"

enum enMenu
{
  ShowClientList = 1,
  AddNewClient = 2,
  DeleteClient = 3,
  UpdateClient = 4,
  FindClient = 5,
  Exit = 6
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
  case (enMenu::FindClient):
    AccNum = inputs::PromptReader("Enter AccountNumber: ");
    FindRecord(AccNum, vRecs, fname);
    return (std::stoi(inputs::PromptReader("\nPress [0] to get back to Main Menu ")));
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

bool FindRecord(string &AccNum, vector <string> &vRecs, string fname)
{
  vector <string> vCntr;
  
  if (CheckRecord(AccNum, vRecs, fname)) {
    vCntr = splitLine(GetSingleRecord(AccNum, vRecs, fname), "#/\\#");
    displayLib::DisplaySingleRecord(LineToRecord(vCntr));
    return (true);
  } else
    cout<<"Client with Account Number (" + AccNum + ") is Not Found!\n";

  return (false);
}

vector <string> PerformDeletion(string &AccNum, vector <string> &CurrentRecs)
{
  vector <string> NewRecs;
  short pos = 0;
  
  for (const string &c:CurrentRecs) {
    pos = c.find("#/\\");
    if (c.substr(0, pos) != AccNum)
      NewRecs.push_back(c);
  }
  return (NewRecs);
}

vector <string> DeleteClientRec(string &AccNum, vector <string> &vRecs, string fname)
{
  char Action;
  
  if (FindRecord(AccNum, vRecs, fname))
    Action = inputs::PromptReader("\nDo you want to delete this client (Y|N)? ")[0];

  if (Action == 'Y' || Action == 'y') {
    vRecs = PerformDeletion(AccNum, vRecs);
    SaveTruncatedRecordsToFile(vRecs);
  }

  return (vRecs);
}

