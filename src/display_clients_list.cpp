#include "../headers/library/handlers.hpp"
#include "../headers/library/strLib.hpp"
#include "../headers/library/displayLib.hpp"
#include "../headers/trx_handler.hpp"
#include "../headers/core.hpp"

using handlers::ClientsCount;

string ClientTable()
{
  string Content = "";
  
  Content += " | Accout Number  ";
  Content += " | Pin Code  ";
  Content += " | Client Name\t\t";
  Content += " | Phone\t\t";
  Content += " | Balance  \n";

  return (Content);
}

void DisplayClientsList(vector <string> &vClientRecs)
{
  cout<<str::spaceLimiter("\t", 30)<<"Client List ("<<handlers::ClientsCount(vClientRecs)<<") Client(s)."<<endl;
  displayLib::DisplayTable(ClientTable(), "=====", 19, vClientRecs, true);
}

string BalanceTable()
{
  string Content = "";
  
  Content += " | Accout Number  ";
  Content += " | " + str::spaceLimiter("Client Name", 22);
  Content += " | Balance  \n";

  return (Content);
}

double TotalBalances(vector <string> &vRecs)
{
  double TotalBalances = 0;
  stClient c;
  
  for (const string &r:vRecs) {
    c = LineToRecord(splitLine(r, "#/\\#"));
    TotalBalances += c.AccountBalance;
  }

  return (TotalBalances);
}

void DisplayBalancesTable(vector <string> &vClientRecs)
{
  cout<<"\t\t   Balances List ("<<ClientsCount(vClientRecs)<<") Client(s)."<<endl;
  displayLib::DisplayTable(BalanceTable(), "=====", 12, vClientRecs, false);
  cout<<"\t\t  Total Balances = ["<<TotalBalances(vClientRecs)<<"]\n"<<endl;
}
