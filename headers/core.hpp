#ifndef CORE_H
#define CORE_H

#include <iostream>
#include <vector>

using std::string;
using std::vector;

struct stClient
{
  string AccountNumber;
  uint16_t PinCode;
  string Fullname;
  string Phone;
  double AccountBalance;
};

vector <stClient> SaveRecords();
#endif /* CORE_H */
