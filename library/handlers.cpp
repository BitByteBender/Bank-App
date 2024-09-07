#include "../headers/library/handlers.hpp"
#include "../headers/library/strLib.hpp"

using str::spaceLimiter;

namespace handlers
{

  bool CheckAccNum(string &AccNum)
  {
    vector <string> vClientRecs = LoadRecordsFromFile("Recs");

    for (const string &Cl:vClientRecs)
      if (Cl.substr(0, Cl.find("#/\\#")) == AccNum) return (true);
    
    return (false);
  }

  uint16_t ClientsCount(vector <string> &vClients)
  {
    vector <string>::iterator i;
    uint16_t counter = 0;

    for (i = vClients.begin(); i != vClients.end(); i++)
      counter++;

    return (counter);
  }

  void LoadClientsRecs(vector <string> &vClientRecs)
  {
    vector <stClient> vClients = LineToClientsRecord(vClientRecs);
    
    for (const stClient &c:vClients) {
      cout<<" | "<<spaceLimiter(c.AccountNumber, 15);
      cout<<" | "<<spaceLimiter(to_string(c.PinCode), 10);
      cout<<" | "<<spaceLimiter(c.Fullname, 22);
      cout<<" | "<<spaceLimiter(c.Phone, 21);
      cout<<" | "<<stod(spaceLimiter(to_string(c.AccountBalance), 2))<<'\n';
    }
  }
}
