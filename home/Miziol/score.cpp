#include<iostream>
#include<string.h>

using namespace std;


int main()
{
	int n,w=0,v=0;
	string s;

	cin >> n;

	cin.ignore(1);
	
	for(int i = 0; i < n; i++)
		{

		getline (cin, s);

		for(int j = 0; j < s.length() + 1; j++)
			{
			if(s[j]=='o'||s[j]=='O')
				{
				v++;
				w = w + v;
				}
			else
				{
				v = 0;
				}
			}

		cout << w << endl;

		w = 0;
		}


	return 0;
}