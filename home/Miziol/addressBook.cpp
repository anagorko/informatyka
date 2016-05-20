#include<fstream>
#include<iostream>
#include<string>
#include<vector>

#include"UI.h"
#include"Book_library.h"

using namespace std;

int main(int argc, char* argv[])
{
	Book Book1;

	if(argc == 1) welcomeHelp();
	else
	{
		Book1.openFile(argv[1]);
	}

	return 0;
}