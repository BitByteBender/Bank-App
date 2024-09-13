#include "../headers/library/displayLib.hpp"
#include "../headers/library/handlers.hpp"
#include "../headers/library/strLib.hpp"

namespace displayLib
{
  void DisplayHeader(const char *Head)
  {
    cout<<"========================================\n"
	<<Head<<"\n"
	<<"========================================\n";
  }
  
  void MainMenuScreen(const char *Head)
  {
    DisplayHeader(Head);
    cout<<"\t[1]> Show Client List\n"
	<<"\t[2]> Add New Client\n"
	<<"\t[3]> Delete Client\n"
	<<"\t[4]> Update Client Info\n"
	<<"\t[5]> Find Client\n"
	<<"\t[6]> Transactions\n"
	<<"\t[7]> Users Manager\n"
	<<"\t[8]> Logout";
    cout<<"\n========================================\n"<<endl;
  }

  void TransactionsScreen(const char *Head)
  {
    DisplayHeader(Head);
    cout<<"\t[1]> List Of Balances\n"
	<<"\t[2]> Deposit\n"
	<<"\t[3]> Withdraw\n"
	<<"\t[4]> Main Menu"
	<<"\n========================================\n"<<endl;
  }
  
  void Styler(string Border, uint16_t Len)
  {
    while (Len != 0) {
      cout<<Border;
      Len--;
    }
    cout<<'\n';
  }
  
  void DisplayTable(string Content, string TableStyling, uint16_t Len, vector <string> &vClientRecs, bool Trigger=true)
  {
    uint16_t i = 0;

    Styler(TableStyling, Len);
    
    for (i = 0; i < 2 ; ++i) {
      if (i == 0) {
	cout<<Content;
	Styler(TableStyling, Len);
      } else {
	if (!vClientRecs.empty()) {
	  handlers::LoadClientsRecs(vClientRecs, Trigger); 
	} else
	  cout<<str::spaceLimiter("\t\t\t\t\tEmpty Client List", 22)<<'\n';
      }
      Styler(TableStyling, Len);

    }
  }

  void DisplayRecords(vector <stClient> &vClients)
  {
    cout<<"Checking: "<<endl;
    for (const stClient &cl:vClients) {
      cout<<"Account Number: "<<cl.AccountNumber<<'\n'
	  <<"Pincode: "<<cl.PinCode<<'\n'
	  <<"Fullname: "<<cl.Fullname<<'\n'
	  <<"Phone Number: "<<cl.Phone<<'\n'
	  <<"Account Balance: "<<cl.AccountBalance<<endl;
    }
  }

  void DisplaySingleRecord(stClient Client)
  {
    cout<<"Account Number: "<<Client.AccountNumber<<'\n'
	<<"Pincode: "<<Client.PinCode<<'\n'
	<<"Fullname: "<<Client.Fullname<<'\n'
	<<"Phone Number: "<<Client.Phone<<'\n'
	<<"Account Balance: "<<Client.AccountBalance<<endl;
  }
}
