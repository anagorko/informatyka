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

		for (int i = 2; i < argc; i++)
		{
			string test;
			test = argv[i];

			if(test == "print")
			{
				Book1.printBook();
			}
		}
	}

	return 0;
}