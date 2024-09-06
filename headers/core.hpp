#ifndef CORE_H
#define CORE_H

#include <iostream>
#include <vector>
#include <fstream>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::fstream;
using std::ios;

struct stClient
{
  string AccountNumber;
  uint16_t PinCode;
  string Fullname;
  string Phone;
  double AccountBalance;
};

vector <stClient> SaveRecords();
vector <string> SaveRecords(vector <stClient> &vClients);
void SaveRecordsToFile(vector <string> &ClientRecs);
#endif /* CORE_H */
