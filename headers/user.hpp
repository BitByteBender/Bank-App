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
bool IsValid(stUser usr, stUser compareUsr);
bool OnAuthValidation(stUser usr, vector <stUser> vUsers);
int16_t CalcPermission(vector <uint16_t> vNums);
string ReverseString(string &Permission);
int16_t getUserPermission(stUser usr, vector <stUser> &vUsers);
vector <uint16_t> RecordPermissions(int16_t &Permission);
void OnAuthentication(void);

#endif /* USER_H */
