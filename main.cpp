#include "headers/library/displayLib.hpp"
#include "headers/core.hpp"

using std::cout;
using std::cin;
using std::endl;
using displayLib::MainMenuScreen;
using displayLib::DisplayClientList;
using displayLib::DisplayRecords;


int main(void)
{
  vector vClients = SaveRecords();
  vector vRecs = SaveRecords(vClients);
  /*MainMenuScreen("Main Menu Screen");
  cout<<'\n';
  DisplayClientList("=====", 19);*/
  DisplayRecords(vClients);
  //SaveRecordsToFile(vRecs);
  //cout<<"Loading files:\n";
  //cout<<LoadRecordsFromFile("Recs")[0]<<'\n';
  return (0);
}
