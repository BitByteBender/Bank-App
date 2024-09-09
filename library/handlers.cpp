#include "../headers/library/handlers.hpp"
#include "../headers/library/strLib.hpp"
#include "../headers/library/inputLib.hpp"
#include "../headers/crud.hpp"

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

  void LoadClientsRecs(vector <string> &vClientRecs, bool Trigger=true)
  {
    vector <stClient> vClients = LineToClientsRecord(vClientRecs);
    
    for (const stClient &c:vClients) {
      cout<<" | "<<spaceLimiter(c.AccountNumber, 15);
      if (Trigger)
	cout<<" | "<<spaceLimiter(to_string(c.PinCode), 10);
      cout<<" | "<<spaceLimiter(c.Fullname, 22);
      if (Trigger)
	cout<<" | "<<spaceLimiter(c.Phone, 21);
      cout<<" | "<<stod(spaceLimiter(to_string(c.AccountBalance), 2))<<'\n';
    }
  }

  string GetSingleRecord(string &AccNum, vector <string> &vRecs, string fname)
  {
    vRecs = LoadRecordsFromFile(fname);
    short pos = 0;
  
    if (!vRecs.empty()) {
      for (const string &r:vRecs) {
	pos = r.find("#/\\#");
	if (r.substr(0, pos) == AccNum)
	  return (r);
      }
    }
    return ("None");
  }
  
  bool CheckRecord(string &AccNum, vector <string> &vRecs, string fname)
  {
    return (GetSingleRecord(AccNum, vRecs, fname) != "None");
  }

  vector <string> PerformDeletion(string &AccNum, vector <string> &CurrentRecs)
  {
    vector <string> NewRecs;
    short pos = 0;
  
    for (const string &c:CurrentRecs) {
      pos = c.find("#/\\");
      if (c.substr(0, pos) != AccNum)
	NewRecs.push_back(c);
    }
    return (NewRecs);
  }

  vector <string> PerformUpdate(string &AccNum, vector <string> &CurrentRecs)
  {
    vector <string> vNew;
    short pos = 0;
    
    for (string &r:CurrentRecs) {
      pos = r.find("#/\\#");
      if (r.substr(0, pos) == AccNum) {
	string Msg = "Updating Account ("+ AccNum +") details...\n";
	r = str::Tokenizer(inputs::SaveRec(AccNum), "#/\\#");
	vNew.push_back(r);
      } else
	vNew.push_back(r);
    }
    
    return (vNew);
  }

  char MakeDecision(string &AccNum, vector <string> &vRecs, string fname, const char *PlaceHolder)
  {
    char Action = 'n';
  
    if (FindRecord(AccNum, vRecs, fname))
      Action = inputs::PromptReader(PlaceHolder)[0];

    return (Action);
  }
}
