#include "../headers/core.hpp"
#include "../headers/library/inputLib.hpp"
#include "../headers/library/strLib.hpp"

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

vector <string> SaveRecords(vector <stClient> &vClients)
{
  vector <string> vClientRecs;

  for (const stClient &cl:vClients) {
    vClientRecs.push_back(str::Tokenizer(cl, "#/\\#"));
  }

  return (vClientRecs);
}
