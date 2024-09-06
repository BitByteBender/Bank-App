#include "../headers/core.hpp"
#include "../headers/library/inputLib.hpp"
#include <vector>

using std::vector;
using std::cout;
using inputs::LoadRecord;
using inputs::PromptReader;

vector <stClient> SaveRecords()
{
  vector <stClient> vClients;
  stClient Client;
  char Decision;
  
  do {
    Client = LoadRecord("Adding New Client:\n");
    vClients.push_back(Client);
    Decision = char(PromptReader("Do you want to add more Clients (Y/N)? ")[0]);
  } while (Decision == 'y' || Decision == 'y');

  return (vClients);
}
