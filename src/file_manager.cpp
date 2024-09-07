#include "../headers/core.hpp"

void SaveRecordsToFile(vector <string> &vClientRecs)
{
  fstream File;
  File.open("Recs", ios::out | ios::app);
  
  if (File.is_open()) {
    if (!vClientRecs.empty()) {
      for (const string &cl:vClientRecs) {
	File<<cl<<'\n';
      }
    }
    File.close();
  }
}

void SaveSingleRecToFile(string Record)
{
  fstream File;
  File.open("Recs", ios::out | ios::app);
  
  if (File.is_open()) {
    if (!Record.empty())
      File<<Record<<'\n';
    File.close();
  }
}

vector <string> LoadRecordsFromFile(string fname)
{
  vector <string> vClientRecs;
  fstream File;
  string line;
  File.open(fname, ios::in);

  if (File.is_open()) {
    while (getline(File, line)) {
      if (line != "") {
	vClientRecs.push_back(line);
      }
    }
  }
 
  return (vClientRecs);
}

vector <string> LoadSingleRecordFromFile(string fname)
{
  vector <string> vClientRec;

  
  return (vClientRec);
}
