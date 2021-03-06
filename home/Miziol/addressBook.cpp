#include<fstream>
#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<algorithm>

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
			if(test == "delete")
			{
				int dp = 0;

				i++;
				test = argv[i];

				for(int i = 0; i < test.size(); i++)
				{
					dp = dp * 10 + test[i] - 48;
				}

				deletePerson(dp);
			}
			if(test == "edit")
			{
				int ep = 0;

				i++;
				test = argv[i];

				for(int i = 0; i < test.size(); i++)
				{
					ep = ep * 10 + test[i] - 48;
				}

				editPerson(ep);
			}
			if(test == "sort")
			{
				Book1.sortBook();
				cout << "sort";
			}
		}

		Book1.saveFile(argv[1]);
	}

	return 0;
}