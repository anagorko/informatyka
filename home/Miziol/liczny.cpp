#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class long_number
{
public:

	string n;

	bool operator == ( const long_number& p)
	{
		if( n.size() != p.n.size() ) return false;

		for ( int i = 0; i < n.size(); i++)
		{
			if( n[i] != p.n[i] ) return false;
		}

		return true;
	}

	bool operator < ( const long_number& p)
	{
		return ( n.size() < p.n.size() );
	}

	bool operator > ( const long_number& p)
	{
		return ( n.size() > p.n.size() );
	}
};

int main()
{
	vector <long_number> list;

	long_number r;

	while ( !cin.eof() )
	{
		cin >> r.n;

		list.push_back(r);
	}

	sort( list.begin(), list.end() );

	for ( int i = 0; i < list.size(); i++)
	{
		cout << list[i].n << endl;
	}
}