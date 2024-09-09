#include "../headers/library/handlers.hpp"
#include "../headers/library/inputLib.hpp"
#include "../headers/library/strLib.hpp"
#include "../headers/crud.hpp"

double Deposit(double cBalance, double Amount)
{
  return (cBalance + Amount);
}

vector <string> performAction(string &AccNum, vector <string> &vRecs, double NewAmount)
{
  vector <string> vNewRecs;
  stClient cl;
  
  for (string &r:vRecs) {
    if (r.substr(0, r.find("#/\\#")) == AccNum) {
      cl = LineToRecord(splitLine(r, "#/\\#"));
      cl.AccountBalance = Deposit(cl.AccountBalance, NewAmount);
      r = str::Tokenizer(cl, "#/\\#");
      vNewRecs.push_back(r);
    } else
      vNewRecs.push_back(r);
  }
  
  return (vNewRecs);
}

double CallToAction(string &AccNum, vector <string> &vRecs, string fname, string Type)
{
  char Action = 'n';
  double NewAmount = 0;
  
  do {
    AccNum = inputs::PromptReader("\nPlease enter a valid account number: ");
    if (FindRecord(AccNum, vRecs, fname)) {
      NewAmount = stod(inputs::PromptReader("\nEnter a " + Type + " amount: "));
      Action = char(inputs::PromptReader("\nAre you sure you want to perform this transaction? (y/n) ")[0]);
    }
  } while (Action == 'n');

  return (NewAmount);
}

double getNewBalance(string &AccNum, vector <string> &vRecs)
{
  stClient cl;
  
  for (const string &r:vRecs) {
    if (r.substr(0, r.find("#/\\#")) == AccNum) {
      cl = LineToRecord(splitLine(r, "#/\\#"));
      return (cl.AccountBalance);
    }
  }

  return (0);
}

inline bool CheckBalance(string &AccNum, vector <string> &vRecs, double NewAmount)
{
  return (getNewBalance(AccNum, vRecs) >= NewAmount);
}

void DisplayResult(string &AccNum, vector <string> &vRecs, double NewAmount, string PerformedAction)
{
  vector <string> vHolder = LoadRecordsFromFile("Recs");

  
  if (CheckBalance(AccNum, vHolder, NewAmount) || PerformedAction[0] == 'd') {
    cout<<"\nYou have successfully "<<PerformedAction<<" ["<<NewAmount<<"].\n"
	<<"Your New Balance is >>: "<<getNewBalance(AccNum, vRecs)<<'\n'; 
  } else
    cout<<"\nNot Enough Balance\n";

}

vector <string> UpdateBalance(string &AccNum, vector <string> &vRecs, string fname, string Type)
{
  double NewAmount = CallToAction(AccNum, vRecs, fname, Type);
  
  if (NewAmount > 0) {
    string PerformedAction = "";
    if (Type[0] == 'd') {
      vRecs = performAction(AccNum, vRecs, NewAmount);
      PerformedAction = "deposited";
    } else {
      if (CheckBalance(AccNum, vRecs, NewAmount)) {
	vRecs = performAction(AccNum, vRecs, (NewAmount * -1));
	PerformedAction = "withdrawn";
      }
    }
    DisplayResult(AccNum, vRecs, NewAmount, PerformedAction);
  }
  
  return (vRecs);
}
