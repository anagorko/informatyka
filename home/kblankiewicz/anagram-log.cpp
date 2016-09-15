#include<iostream>
#include<vector>
#include<algorithm>
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

	string print()
	{
	    return n;
	}

    string pokaz_alfabet()
    {
        return q;
    }

};

ostream& operator<<(ostream& s, Slowo a)
{
	s << a.print();
	return s;
}

int main()
{
    vector <Slowo> v;
    string p;

    while(!cin.eof())
    {
        cin>>p;
        Slowo a = Slowo(p);
        v.push_back(a);
        p = "0"
    }


    sort(v.begin(), v.end());

    string z = v[0].pokaz_alfabet();
    string y = v[0].print();
    cout << y;
    for(int i = 1; i < v.size(); i++)
    {
        if(z == v[i].pokaz_alfabet()) cout<<"  ";
        else cout<<endl;
        z = v[i].pokaz_alfabet();
        y = v[i].print();
        cout<<y;
    }
}



