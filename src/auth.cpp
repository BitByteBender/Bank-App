#include "../headers/user.hpp"
#include "../headers/library/inputLib.hpp"
#include <cmath>

stUser PromptUser()
{
  stUser usr;

  usr.Username = inputs::PromptReader("Enter Username: ");
  usr.Password = stoi(inputs::PromptReader("Enter Password: "));

  return (usr);
}

stUser LineToRec(vector <string> vLineUsr)
{
  stUser usr;

  usr.Username = vLineUsr.at(0);
  usr.Password = stoi(vLineUsr.at(1));
  usr.Permissions = stoi(vLineUsr.at(2));
  
  return (usr);
}

vector <stUser> LoadUsersToVecRec(vector <string> vUsrRec)
{
  vector <stUser> vUsers;

  for (const string &u:vUsrRec) {
    vUsers.push_back(LineToRec(splitLine(u, "#/\\#")));
  }
  
  return (vUsers);
}

bool IsValid(stUser usr, stUser compareUsr)
{
  return (compareUsr.Username == usr.Username && compareUsr.Password == usr.Password);
}

bool OnAuthValidation(stUser usr, vector <stUser> vUsers)
{
  for (const stUser &u:vUsers) {
    if (IsValid(usr, u))
      return (true);
  }

  return (false);
}

int16_t getUserPermission(stUser usr, vector <stUser> &vUsers)
{
  for (const stUser &u:vUsers) {
    if (IsValid(usr, u))
      return (u.Permissions);
  }

  return (0);
}

vector <uint16_t> RecordPermissions(int16_t &Permission)
{
  vector <uint16_t> vPermissions;

  if (Permission == -1) {
    vPermissions = {1, 2, 3, 4, 5, 6, 7, 8};
  } else {
    uint16_t i = 0;

    for (i = 0; i <= 7; ++i) {
      if (Permission >= pow(2, (7-i))) {
	Permission -= pow(2, (7-i));
	vPermissions.push_back(8 - i);
      }
    }
  }
  
  return (vPermissions);
}

int16_t CalcPermission(vector <uint16_t> vNums)
{
  int16_t Permission = 0;

  for (const uint16_t &n:vNums) {
    Permission += pow(2, (n-1));
  }
  
  return (Permission);
}

string ReverseString(string &Permission)
{
  string Temp = Permission;
  uint16_t i = 0;

  Permission.clear();
  for (i = Temp.length() - 1; i != '\0'; i--) {
    Permission += Temp[i];
  }

  Permission += Temp[i];
  
  return (Permission);
}
