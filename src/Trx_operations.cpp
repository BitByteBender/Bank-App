#include "../headers/trx_handler.hpp"
#include "../headers/library/handlers.hpp"

void DisplayBalancesTable(vector <string> &vRecs)
{
  cout<<"\t\tBalances List ("<<handlers::ClientsCount(vRecs)<<") Client(s)."<<endl;
}
