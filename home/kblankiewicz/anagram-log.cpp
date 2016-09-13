#include<iostream>
#include<vector>
using namespace std;

string alfabet(string s)
{
	string t = s;
	int p, q;

	for(int i = 0; i < s.length();i++)
	{
		for(int j = 0; j < s.length() - 1; j++)
		{
			p = t[j];
			q = t[j + 1];
			if(p > q)
			{
				t[j] = q;
				t[j + 1] = p;
			}
		}
	}
	return t;
}

class Slowo
{
	string n, q; 

public:

	Slowo (string _n)
	{
		n = _n;
		q = alfabet(_n);	
	}

	bool operator==(const Slowo& s) const
	{
		if(q == s.q)
		{
			return true;
		}
		else return false;
	}

	bool operator<(const Slowo& s) const
	{
		if(q < s.q)
		{
			return true;
		}
		else return false;
	}
	
	ostream& operator<<(ostream& s)
	{
		s << n;
		return s;
	}

	
};

int main()
{


}




