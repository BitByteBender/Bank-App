//#include "headers/library/displayLib.hpp"
#include "headers/core.hpp"
/*
using displayLib::MainMenuScreen;
using displayLib::DisplayTable;
using displayLib::DisplayRecords;
*/

int main(void)
{
  //vector <stClient> vClients = SaveRecords();
  //vector <string> vRecs = SaveRecords(vClients);
  //DisplayRecords(vClients);
  //SaveRecordsToFile(vRecs);
  //cout<<"Loading files:\n";
  //cout<<LoadRecordsFromFile("Recs")[0]<<'\n';
  //MainMenuScreen("Main Menu Screen");
  cout<<'\n';
  //DisplayTable("=====", 19);
  vector <string> vRecs = LoadRecordsFromFile("Recs");
  //vClients = LineToClientsRecord(vRecs);

  DisplayClientsList(vRecs);
  return (0);
}
