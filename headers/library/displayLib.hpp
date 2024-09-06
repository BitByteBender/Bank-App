#ifndef DISPLAYLIB_H
#define DISPLAYLIB_H

#include <iostream>

using std::cout;
using std::endl;

namespace displayLib
{
  void MainMenuScreen(const char *Head)
  {
    cout<<"========================================\n"
	<<"             "<<Head<<"                 \n"
	<<"========================================\n";
    cout<<"        [1]> Show Client List\n"
	<<"        [2]> Add New Client\n"
	<<"        [3]> Delete Client\n"
	<<"        [4]> Update Client Info\n"
	<<"        [5]> Find Client\n"
	<<"        [6] Exit";
    cout<<"\n========================================\n"<<endl;
  }
};

#endif /* DISPLAYLIB_H */
