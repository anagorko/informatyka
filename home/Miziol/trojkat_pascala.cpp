#include<iostream>

using namespace std;

int main()
{
	int t [30][30];
	t[0][0] = 1;
	t[0][1] = 1;
	t[1][1] = 1;
	for ( int i = 2; i < 30; i++)
	{
		t[0][i] = 1;
		t[i][i] = 1;
		for ( int j = 1; j < i; j++)
		{
			t[j][i] = t[j-1][i-1] + t[j-1][i];
		}
	}

	cout << "a)\n";
	for ( int i = 10; i <=30; i = i + 10)
	{
		cout << i << " " << t[i/2][i-1];
	}
}