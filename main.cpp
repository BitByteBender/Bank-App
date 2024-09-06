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
  /*MainMenuScreen("Main Menu Screen");
  cout<<'\n';
  DisplayClientList("=====", 19);*/
  DisplayRecords(vClients);
  
  return (0);
}
