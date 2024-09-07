#ifndef HANDLERS_H
#define HANDLERS_H

#include "../core.hpp"

namespace handlers
{
  bool CheckAccNum(string &AccNum);
  uint16_t ClientsCount(vector <string> &vClients);
  void LoadClientsRecs(vector <string> &vClientRecs);
}

#endif /* HANDLERS_H */
