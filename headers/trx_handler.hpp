#ifndef TRX_HANDLER_H
#define TRX_HANDLER_H

#include "core.hpp"

void DisplayBalancesTable(vector <string> &vRecs);
vector <string> UpdateBalance(string &AccNum, vector <string> &vRecs, string fname, string Type);

#endif /* TRX_HANDLER_H */
