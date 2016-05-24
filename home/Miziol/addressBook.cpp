#include<fstream>
#include<iostream>
#include<string>
#include<vector>
#include<math.h>

#include"Book_library.h"
Book Book1;

#include"UI.h"

using namespace std;

int main(int argc, char* argv[])
{

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
				print();
			}
			if(test == "add")
			{
				add();
			}
		}

		Book1.saveFile(argv[1]);
	}

	return 0;
}