#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class word
{
public:

	string s;

	bool operator ==(const word& p)
	{
		return (s == p.s);
	}

	bool operator <(const word& p)
	{
		int n = s.size();

		if( p.s.size() < s.size() ) n = p.s.size();

		for ( int i = 0; i < n; i++)
		{
			if( (int) s[ s.size() - i] < (int) p.s[ p.s.size() - i] )
			{
				return true;
			}
		}

		if ( s.size() < p.s.size() ) return true;

		return false;
	}

	bool operator >(const word& p)
	{
		int n = p.s.size();

		if( s.size() < p.s.size() ) n = s.size();

		for ( int i = 0; i < n; i++)
		{
			if( (int) s[ s.size() - i] > (int) p.s[ p.s.size() - i] )
			{
				return true;
			}
		}

		if ( s.size() > p.s.size() ) return true;

		return false;
	}
};

int main()
{
	vector <word> list;

	word r;

	while ( !cin.eof() )
	{
		cin >> r.s;

		list.push_back(r);
	}

	sort( list.begin(), list.end() );
}