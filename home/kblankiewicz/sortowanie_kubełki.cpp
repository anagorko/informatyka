#include<vector>
#include<iostream>
using namespace std;

vector <int> v;

int main()
{
	int c;
	cout << "podaj maksymalną wielkość wprowadzanych liczb:" << endl;
	cin >> c;
	
	int t[c];
	for(int i = 0; i < c; i++)
	{
		t[i] = 0;
	}

	cout << "i liczby:" << endl;
	int n;
	while(cin >> n)
	{
		t[n] += 1;
	}
	
	for(int i = 0; i < c; i++)
	{
		for(int j = 0; j < t[i]; j++)
		{
			cout << i << " ";
		}
	}
	cout << endl;
}
