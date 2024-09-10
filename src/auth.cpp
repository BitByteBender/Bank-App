#include "../headers/user.hpp"
#include "../headers/library/inputLib.hpp"

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

bool IsValid(stUser usr, vector <stUser> vUsers)
{
  for (const stUser &u:vUsers) {
    if (u.Username == usr.Username && u.Password == usr.Password)
      return (true);
  }

  return (false);
}

void OnAuthentication(const stUser usr, const vector <stUser> vUsers)
{
  if (IsValid(usr, vUsers)) {
    cout<<'\n';
    OnBeginPlay();
  } else
    cout<<"Not a valid user"<<endl;
}
