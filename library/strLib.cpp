
#include "../headers/library/strLib.hpp"


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

  string spaceLimiter(string Container, uint16_t max)
  {
    int16_t len = max - Container.length();
    
    for (uint16_t i = 0; i < len; ++i) Container += " ";
    
    return (Container);
  }

  /*stClient LineToRecord(string Rec, string DELIM)
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
    }*/

  
  /*
    stClient LineToRecord(vector <string> &vStr)
    {
    stClient Client;

    Client.AccountNumber = vStr[0];
    Client.PinCode = stoi(vStr[1]);
    Client.Fullname = vStr[2];
    Client.Phone = vStr[3];
    Client.AccountBalance = stod(vStr[4]);
    
    return (Client);
    }*/
}
