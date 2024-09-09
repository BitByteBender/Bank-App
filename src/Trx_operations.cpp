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

vector <string> UpdateBalance(string &AccNum, vector <string> &vRecs, string fname, string Type)
{
  double NewAmount = CallToAction(AccNum, vRecs, fname, Type);
  
  if (NewAmount > 0) {
    string PerformedAction = "";
    if (Type[0] == 'd') {
      vRecs = performAction(AccNum, vRecs, NewAmount);
      PerformedAction = "deposited";
    }
    else {
      vRecs = performAction(AccNum, vRecs, (NewAmount * -1));
      PerformedAction = "withdrawn";
    }
    cout<<"You have successfully "<<PerformedAction<<" ["<<NewAmount<<"].\n"
	<<"Your New Balance is >>: "<<getNewBalance(AccNum, vRecs)<<'\n';
  }
  
  return (vRecs);
}
