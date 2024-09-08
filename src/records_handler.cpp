#include "../headers/core.hpp"
#include "../headers/library/inputLib.hpp"
#include "../headers/library/strLib.hpp"

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

stClient LineToRecord(vector <string> vStr)
{
  stClient Client;
  
  Client.AccountNumber = vStr[0];
  Client.PinCode = stoi(vStr[1]);
  Client.Fullname = vStr[2];
  Client.Phone = vStr[3];
  Client.AccountBalance = stod(vStr[4]);
  
  return (Client);
}

vector <string> splitLine(string Line, string DELIM)
{
  vector <string> vStr;
  short pos = Line.find(DELIM);

  while (pos != string::npos) {
    vStr.push_back(Line.substr(0, pos));
    Line.erase(0, pos + DELIM.length());
    pos = Line.find(DELIM);
  }

  if (!Line.empty()) {
    vStr.push_back(Line);
    Line.clear();
  }
  
  return (vStr);
}

vector <stClient> LineToClientsRecord(vector <string> &vClientRecs)
{
  vector <stClient> vClients;

  for (const string &c:vClientRecs) {
    vClients.push_back(LineToRecord(splitLine(c, "#/\\#")));
  }
 
  return (vClients);
}
