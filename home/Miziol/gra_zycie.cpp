#include<iostream>

using namespace std;

int sasiedzi()
{

}

int main()
{
	char s[12][20], n[12][20];

	for (int i = 0; i < 12; i++)
	{
		cin.ignore(1,'\n');
		//cin.ignore(1,'\t');
		for (int j = 0; j < 20; j++)
		{
			cin >> s[i][j];
		}
	}

	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			cout << s[i][j];
		}
		cout << endl;
	}

	//update planszy

	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			cout << s[i][j];
		}
		
	}
}