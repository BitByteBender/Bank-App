#ifndef HANDLERS_H
#define HANDLERS_H

#include "../core.hpp"

namespace handlers
{
  bool CheckAccNum(string &AccNum);
  uint16_t ClientsCount(vector <string> &vClients);
  void LoadClientsRecs(vector <string> &vClientRecs, bool Trigger);
  string GetSingleRecord(string &AccNum, vector <string> &vRecs, string fname);
  bool CheckRecord(string &AccNum, vector <string> &vRecs, string fname);
  char MakeDecision(string &AccNum, vector <string> &vRecs, string fname, const char *PlaceHolder);
  vector <string> PerformDeletion(string &AccNum, vector <string> &CurrentRecs);
  vector <string> PerformUpdate(string &AccNum, vector <string> &CurrentRecs);
}

#endif /* HANDLERS_H */
