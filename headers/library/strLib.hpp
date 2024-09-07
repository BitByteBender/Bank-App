#ifndef STRLIB_H
#define STRLIB_H

#include "../core.hpp"

namespace str
{
  string Tokenizer(stClient Client, string DELIM);
  //stClient LineToRecord(string Rec, string DELIM="#/\\#");
  stClient LineToRecord(vector <string> &vStr);
  string spaceLimiter(string Container, uint16_t max);
}


#endif /* STRLIB_H */
