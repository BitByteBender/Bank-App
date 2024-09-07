#ifndef CORE_H
#define CORE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>


using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::vector;
using std::fstream;
using std::ios;

struct stClient
{
  string AccountNumber;
  uint16_t PinCode;
  string Fullname;
  string Phone;
  double AccountBalance;
};

vector <stClient> SaveRecords();
vector <string> SaveRecords(vector <stClient> &vClients);
void SaveRecordsToFile(vector <string> &ClientRecs);
vector <string> LoadRecordsFromFile(string fname);
stClient LineToRecord(string Rec, string DELIM);
vector <stClient> LineToClientsRecord(vector <string> &vClientRecs);
void SaveSingleRecToFile(string Record);
vector <string> splitLine(string Line, string DELIM);
stClient LineToRecord(vector <string> &vStr);
void DisplayClientsList(vector <string> &vClientRecs);
#endif /* CORE_H */

