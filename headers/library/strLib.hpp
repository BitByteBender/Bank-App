#ifndef STRLIB_H
#define STRLIB_H

#include "../core.hpp"

using std::to_string;

namespace str
{
  string Tokenizer(stClient Client, string DELIM)
  {
    string Container = "";

    Container += Client.AccountNumber + DELIM;
    Container += to_string(Client.PinCode) + DELIM;
    Container += Client.Fullname + DELIM;
    Container += Client.Phone + DELIM;
    Container += to_string(Client.AccountBalance);
    
    return (Container);
  }

  stClient LineToRecord(string Rec, string DELIM="#/\\#")
  {
    stClient Client;
    uint16_t pos = Rec.find(DELIM);
  
    Client.AccountNumber = Rec.substr(0, pos);
    Rec.erase(0, pos + DELIM.length());
    
    Client.PinCode = uint16_t(stoi(Rec.substr(0, pos)));
    Rec.erase(0, pos + DELIM.length());
    
    Client.Fullname = Rec.substr(0, pos);
    Rec.erase(0, pos + DELIM.length());
    
    Client.Phone = Rec.substr(0, pos);
    Rec.erase(0, pos + DELIM.length());
    
    Client.AccountBalance = stod(Rec.substr(0, pos));
    return (Client);
  }
}


#endif /* STRLIB_H */
