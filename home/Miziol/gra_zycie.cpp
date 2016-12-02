#include<iostream>

using namespace std;

char s[12][20], n[12][20];

int sasiedzi(int x,int y)
{
	int sum;

	if(s[(x+11)%12][(y+19)%20] == 'X') sum++;
	if(s[(x+11)%12][y] == 'X') sum++;
	if(s[(x+11)%12][(y+1)%20] == 'X') sum++;
	if(s[x][(y+19)%20] == 'X') sum++;
	if(s[x][(y+1)%20] == 'X') sum++;
	if(s[(x+1)%12][(y+19)%20] == 'X') sum++;
	if(s[(x+1)%12][y] == 'X') sum++;
	if(s[(x+1)%12][(y+1)%20] == 'X') sum++;

	return sum;
}

void update_planszy()
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			bool setValue = 1;
			if ( s[i][j] == '.' && sasiedzi ( i, j) == 3 )
			{
				n[i][j] == 'X';
				setValue = 1;
			}
			if ( s[i][j] == 'X' && ( sasiedzi ( i, j) == 3 || sasiedzi ( i, j) == 2 ) )
			{
				n[i][j] == 'X';
				setValue = 1;
			}
			if ( setValue == 0 ) n[i][j] == '.';
		}
	}
}

int main()
{
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

	//rozwiązania

	int a, b;
	char w[12][20];

	update_palnszy(); // drugie pokolenie

	

	
}
