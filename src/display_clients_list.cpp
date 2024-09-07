#include "../headers/library/handlers.hpp"
#include "../headers/library/strLib.hpp"
#include "../headers/library/displayLib.hpp"
#include "../headers/core.hpp"

using handlers::ClientsCount;

void DisplayClientsList(vector <string> &vClientRecs)
{
  cout<<str::spaceLimiter("\t", 30)<<"Client List ("<<handlers::ClientsCount(vClientRecs)<<") Client(s)."<<endl;
  displayLib::DisplayTable("=====", 19, vClientRecs);
}
