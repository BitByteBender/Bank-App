#ifndef USER_H
#define USER_H

#include <iostream>
#include <vector>


using std::string;
using std::vector;

struct stUser
{
  string Username;
  uint16_t Password;
  int16_t Permissions;
};

stUser PromptUser();
stUser LineToRec(vector <string> vLineUsr);
vector <stUser> LoadUsersToVecRec(vector <string> vUsrRec);
bool IsValid(stUser usr, vector <stUser> vUsers);
void OnAuthentication(const stUser usr, const vector <stUser> vUsers);

#endif /* USER_H */
