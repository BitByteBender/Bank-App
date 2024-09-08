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
}
