#include<iostream>
using namespace std;

class liczba
{
public:
	int n;
	bool d[1000001];
	bool f = false;

private:
	liczba()
	{
		for ( int i = 0; i < 1000001; i++)
		{
			d[i] = false;
		}
	}
};