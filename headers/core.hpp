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
void SaveTruncatedRecordsToFile(vector <string> &vTruncatedRecs);

vector <string> LoadRecordsFromFile(string fname);
stClient LineToRecord(string Rec, string DELIM);
vector <stClient> LineToClientsRecord(vector <string> &vClientRecs);
void SaveSingleRecToFile(string Record);
vector <string> splitLine(string Line, string DELIM);
stClient LineToRecord(vector <string> vStr);
void DisplayClientsList(vector <string> &vClientRecs);

uint16_t PrintClientList(vector <string> &vRecs, string fname);
uint16_t InsertNewClient(vector <stClient> &vClients, vector <string> &vRecs, string fname);

string GetSingleRecord(string &AccNum, vector <string> &vRecs, string fname);
bool CheckRecord(string &AccNum, vector <string> &vRecs, string fname);
bool FindRecord(string &AccNum, vector <string> &vRecs, string fname);

vector <string> DeleteClientRec(string &AccNum, vector <string> &vRecs, string fname);

uint16_t Functionalities(uint16_t Picker);
void OnBeginPlay(void);
void OnExit(void);
#endif /* CORE_H */

