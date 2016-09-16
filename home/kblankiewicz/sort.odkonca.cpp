#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string odwrot(string s)
{
	string t = s;
	for(int i = 0; i < s.length(); i++)
	{
		t[i] = s[s.length() - 1 - i];
	}
	return t;
}

class Slowo
{
	string n; //normalne słowo
	string q; //słowo od tyłu
public:

	/*Slowo()
	{

	}*/

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

};

ostream& operator<<(ostream& s, Slowo d)
{
	s << d.getN();
	return s;
}

istream& operator>>(istream& i, Slowo& m)
{
	string z;
	i >> z;
	m.set(z);
	return i;
}

int main()
{
	vector<Slowo> v;
	string k = "nic";
	Slowo a(k);

	while(!cin.eof())
	{
		cin>>a;
		//a.set(k);
		if(cin.eof()) {break;}
		v.push_back(a);
	}

	sort(v.begin(), v.end());

    cout<<endl<<"w kolejności od tyłu alfabetycznej:"<<endl;
    for(int i = 0; i < v.size(); i++)
        {
            cout<<v[i]<<endl;
        }
}


