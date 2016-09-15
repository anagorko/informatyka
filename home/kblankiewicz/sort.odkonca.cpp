#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string odwrot(string s)
{
	string t;
	for(int i = 0; i < s.length(); i++)
	{
		t[i] = s[s.length()-1];
	}
	return t;
}

class Slowo
{
	string n; //normalne słowo
	string q; //słowo od tyłu
public:

	Slowo()
	{
		n = "";
		q = "";	
	}

	Slowo(string _n)
	{
		set(_n);
	}
	
	void set(string x)
	{
		n = x;
		q = odwrot(x);
	}

	string getN()
	{
		return n;
	}

	string getQ()
	{
		return q;
	}

	bool operator==(const Slowo& s) const
	{
		if(q == s.q) return true;
		else return false;
	}
	
	bool operator<(const Slowo& s) const
	{
		if(q < s.q) return true;
		else return false;
	}
	
}

ostream& operator<<(ostream& s, Slowo a)
{
	s << a.getN;
	return s;
}

istream& operator>>(istream& i, Slowo a)
{
	string z;
	i >> z;
	a.set(z);
	return i;
}

int main()
{
	vector<Slowo> v;
	Slowo a;

	while(!cin.eof())
	{
		cin>>a;
		if(cin.eof()) {break};
		v.push_back(a);
	}
	
	sort(v.begin(), v.end());

	for(int i = 0; i < v.size(); i++)
	{
		cout<<v[i]<<endl;
	}
}





