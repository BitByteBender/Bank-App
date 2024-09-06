#ifndef INPUTLIB_H
#define INPUTLIB_H

#include "../core.hpp"

using std::cout;
using std::cin;
using std::string;
using std::ws;

namespace inputs
{
  string PromptReader(const char *Msg)
  {
    string prompt = "";

    cout<<Msg;
    getline(cin >> ws, prompt);
    
    return (prompt);
  }

  stClient LoadRecord(const char *Msg)
  {
    stClient Client;
    cout<<Msg;
    
    Client.AccountNumber = PromptReader("Enter Account Number: ");
    Client.PinCode = uint16_t(stoi(PromptReader("Enter PinCode: ")));
    Client.Fullname = PromptReader("Enter Fullname: ");
    Client.Phone = PromptReader("Enter Phone Number: ");
    Client.AccountBalance = stod(PromptReader("Enter AccountBalance[Initial Deposit]: "));
    
    return (Client);
  }
}

#endif /* INPUTLIB_H */
