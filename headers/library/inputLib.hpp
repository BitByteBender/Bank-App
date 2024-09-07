#ifndef INPUTLIB_H
#define INPUTLIB_H

#include "../core.hpp"
#include <string>

using std::stod;
using std::cout;
using std::cin;
using std::string;
using std::ws;

namespace inputs
{
  string PromptReader(const char *Msg);
  stClient LoadRecord(const char *Msg);
}

#endif /* INPUTLIB_H */
