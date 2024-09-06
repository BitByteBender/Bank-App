#include <iostream>
#include "headers/library/displayLib.hpp"

using std::cout;
using std::cin;
using std::endl;
using displayLib::MainMenuScreen;
using displayLib::DisplayClientList;

int main(void)
{
  MainMenuScreen("Main Menu Screen");
  cout<<'\n';
  DisplayClientList("=====", 19);

  return (0);
}
