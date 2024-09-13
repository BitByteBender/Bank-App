#include "../headers/core.hpp"
#include "../headers/user.hpp"
#include "../headers/library/displayLib.hpp"
#include "../headers/library/inputLib.hpp"

void OnBeginPlay(vector <uint16_t> vNums)
{
  uint16_t Num = 0;
  vector <uint16_t>::iterator iter;
  do {
    displayLib::MainMenuScreen("\t    Main Menu Screen");
    Num = std::stoi(inputs::PromptReader("Choose from the list [1 To 8]: "));
    
    if (Num >= 1 && Num <= 7) {
      for (iter = vNums.begin(); iter != vNums.end(); ++iter) {
	if (*iter == Num) {
	  Functionalities(*iter);
	  break;
	} else if (iter == (vNums.end() - 1) && Num != 8)
	  cout<<"Access Denied\n";
      }
    }
  } while (Num != 8);
}

void TriggerTrxMenu(void)
{
  uint16_t Num = 0;
  
  do {
    displayLib::TransactionsScreen("\tTransactions Menu Screen");
    Num = std::stoi(inputs::PromptReader("Choose from the list [1 To 4]: "));
    if (Num >= 1 && Num <= 4)
      Trx_Menu_Handler(Num);
  } while (Num != 4);
}

void OnAuthentication(void)
{
  int16_t Permission = 0;
  stUser usr;
  vector <stUser> vUsers;

  do {
    usr = PromptUser();
    vUsers = LoadUsersToVecRec(LoadRecordsFromFile("Users"));
    
    if (OnAuthValidation(usr, vUsers)) {
      cout<<'\n';
      Permission = getUserPermission(usr, vUsers);
      OnBeginPlay(RecordPermissions(Permission));
      OnExit();
    } else
      cout<<"Not a valid user"<<endl;
  } while (!OnAuthValidation(usr, vUsers));
}

void OnExit(void)
{
  cout<<"You have been logged out\n";
  OnAuthentication();
}
