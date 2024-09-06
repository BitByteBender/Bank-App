#ifndef HANDLERS_H
#define HANDLERS_H

#include "../core.hpp"

namespace handlers
{

  bool CheckAccNum(string &AccNum)
  {
    vector <string> vClientRecs = LoadRecordsFromFile("Recs");

    for (const string &Cl:vClientRecs)
      if (Cl.substr(0, Cl.find("#/\\#")) == AccNum) return (true);
    
    return (false);
  }
  
}

#endif /* HANDLERS_H */
