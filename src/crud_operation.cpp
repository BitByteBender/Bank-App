#include "../headers/crud.hpp"
#include "../headers/library/inputLib.hpp"
#include "../headers/library/displayLib.hpp"
#include "../headers/library/strLib.hpp"
#include "../headers/library/handlers.hpp"

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

bool FindRecord(string &AccNum, vector <string> &vRecs, string fname)
{
  vector <string> vCntr;
  
  if (handlers::CheckRecord(AccNum, vRecs, fname)) {
    vCntr = splitLine(handlers::GetSingleRecord(AccNum, vRecs, fname), "#/\\#");
    displayLib::DisplaySingleRecord(LineToRecord(vCntr));
    return (true);
  } else
    cout<<"Client with Account Number (" + AccNum + ") is Not Found!\n";

  return (false);
}

vector <string> DeleteClientRec(string &AccNum, vector <string> &vRecs, string fname)
{
  char Action = handlers::MakeDecision(AccNum, vRecs, fname, "\nDo you want to delete this client (Y|N)? ");

  if (Action == 'Y' || Action == 'y') {
    vRecs = handlers::PerformDeletion(AccNum, vRecs);
    SaveTruncatedRecordsToFile(vRecs);
    cout<<"\nClient has been deleted successfully.\n";
  }

  return (vRecs);
}

void UpdateClientRec(string &AccNum, vector <string> &vRecs, string  fname)
{
  char Action = handlers::MakeDecision(AccNum, vRecs, fname, "\nDo you want to update this client (Y|N)? ");

  if (Action == 'y' || Action == 'y') {
    cout<<"\nUpdating Account ("+AccNum+") Details...\n";
    vRecs = handlers::PerformUpdate(AccNum, vRecs);
    SaveTruncatedRecordsToFile(vRecs);
    cout<<"\nClient-Account ("+AccNum+") has been updated successfully."<<endl;
  }
}
