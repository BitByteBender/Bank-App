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
}


#endif /* STRLIB_H */
