#include "headers/core.hpp"
#include "headers/user.hpp"

int main(void)
{

  stUser usr = PromptUser();
  vector vLines = LoadRecordsFromFile("Users");
  vector vUsers = LoadUsersToVecRec(vLines);
  OnAuthentication(usr, vUsers);

  //OnBeginPlay();
  return (0);
}

