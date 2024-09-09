#ifndef DISPLAYLIB_H
#define DISPLAYLIB_H

#include "../core.hpp"

namespace displayLib
{
  void DisplayHeader(const char *Head);
  void MainMenuScreen(const char *Head);
  void TransactionsScreen(const char *Head);
  void Styler(string Border, uint16_t Len);
  void DisplayTable(string Content, string TableStyling, uint16_t Len, vector <string> &vClientRecs, bool Trigger);
  void DisplayRecords(vector <stClient> &vClients);
  void DisplaySingleRecord(stClient Client);
};

#endif /* DISPLAYLIB_H */
