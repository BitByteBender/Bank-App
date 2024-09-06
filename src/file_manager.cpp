#include "../headers/core.hpp"

void SaveRecordsToFile(vector <string> &vClientRecs)
{
  fstream File;
  File.open("Recs", ios::out);
  
  if (File.is_open()) {
    if (!vClientRecs.empty()) {
      for (const string &cl:vClientRecs) {
	File<<cl<<'\n';
      }
    }
    File.close();
  }
}
