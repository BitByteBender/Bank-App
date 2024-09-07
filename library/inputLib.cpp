//#include "../headers/library/inputLib.hpp"
#include "../headers/library/handlers.hpp"

using std::cin;
using std::ws;

namespace inputs
{
  string PromptReader(const char *Msg)
  {
    string prompt{"Empty"};

    cout<<Msg;
    getline(cin >> ws, prompt);
    
    return (prompt);
  }

  stClient LoadRecord(const char *Msg)
  {
    stClient Client;
    cout<<Msg;

    string AccNumber = PromptReader("Enter Account Number: ");
    
    while (handlers::CheckAccNum(AccNumber)) {
      cout<<"Account Number already exists, ";
      AccNumber = PromptReader("re-Enter Account Number: ");
    }
    
    Client.AccountNumber = AccNumber;
    Client.PinCode = uint16_t(stoi(PromptReader("Enter PinCode: ")));
    Client.Fullname = PromptReader("Enter Fullname: ");
    Client.Phone = PromptReader("Enter Phone Number: ");

    cout<<"Enter AccountBalance: ";
    cin>>Client.AccountBalance;
    
    return (Client);
  }
}
