#include "../headers/core.hpp"
#include "../headers/library/inputLib.hpp"
#include "../headers/library/strLib.hpp"
#include "../headers/library/handlers.hpp"

using std::cout;
using std::stod;
using inputs::LoadRecord;
using inputs::PromptReader;


vector <stClient> SaveRecords()
{
  vector <stClient> vClients;
  stClient Client;
  uint16_t i = 0;
  char Decision;
  
  do {
    Client = LoadRecord("Adding New Client:\n");
    vClients.push_back(Client);
    //handlers::AccNumStorage(vClients[i].AccountNumber);
    SaveSingleRecToFile(str::Tokenizer(vClients[i], "#/\\#"));
    Decision = char(PromptReader("Do you want to add more Clients (Y/N)? ")[0]);
    i++;
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

vector <stClient> LineToClientsRecord(vector <string> &vClientRecs)
{
  vector <stClient> vClients;
  vector <string>::iterator iter;
  for (iter = vClientRecs.begin(); iter != vClientRecs.end(); iter++) {
    vClients.push_back(str::LineToRecord(*iter));
  }
  
  return (vClients);
}
