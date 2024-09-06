#ifndef DISPLAYLIB_H
#define DISPLAYLIB_H

#include <iostream>
#include <vector>
#include "../core.hpp"

using std::cout;
using std::endl;
using std::string;
using std::vector;

namespace displayLib
{
  void MainMenuScreen(const char *Head)
  {
    cout<<"========================================\n"
	<<"\t    "<<Head<<"\n"
	<<"========================================\n";
    cout<<"\t[1]> Show Client List\n"
	<<"\t[2]> Add New Client\n"
	<<"\t[3]> Delete Client\n"
	<<"\t[4]> Update Client Info\n"
	<<"\t[5]> Find Client\n"
	<<"\t[6]> Exit";
    cout<<"\n========================================\n"<<endl;
  }

  void Styler(string Border, uint16_t Len)
  {
    while (Len != 0) {
      cout<<Border;
      Len--;
    }
    cout<<'\n';
  }
  
  void DisplayClientList(string TableStyling, uint16_t Len)
  {
    uint16_t i = 0;

    Styler(TableStyling, Len);
    
    for (i = 0; i < 2 ; ++i) {
      if (i == 0) {
	cout<<" | Accout Number  "
	    <<" | Pin Code  "
	    <<" | Client Name\t\t"
	    <<" | Phone\t\t"
	    <<" | Balance  \n";
      } else {
	/* Records here */
	cout<<"\t\t\t\t\tEmpty clients list\n"<<endl;
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
};

#endif /* DISPLAYLIB_H */
