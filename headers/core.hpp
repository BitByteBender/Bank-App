#ifndef CORE_H
#define CORE_H

#include <iostream>

using std::string;

struct stClient
{
  string AccountNumber;
  uint16_t PinCode;
  string Fullname;
  string Phone;
  double AccountBalance;
};

#endif /* CORE_H */
