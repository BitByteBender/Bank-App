#ifndef CRUD_H
#define CRUD_H

#include "core.hpp"

uint16_t PrintClientList(vector <string> &vRecs, string fname);
uint16_t InsertNewClient(vector <stClient> &vClients, vector <string> &vRecs, string fname);
bool FindRecord(string &AccNum, vector <string> &vRecs, string fname);
vector <string> DeleteClientRec(string &AccNum, vector <string> &vRecs, string fname);
void UpdateClientRec(string &AccNum, vector <string> &vRecs, string  fname);

#endif /* CRUD_H */
