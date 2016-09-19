#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class point
{
public:

	int x,y;

	bool operator == (const point& b)
	{
		return (x == b.x && y == b.y);
	}

	bool operator < (const point& b)
	{
		if( x < b.x ) return true;
		if( x == b.x && y < b.y ) return true;

		return false;
	}

	bool operator > (const point& b)
	{
		if( x > b.x ) return true;
		if( x == b.x && y > b.y ) return true;

		return false;
	}
};

int main()
{
	vector <point> p;

	point r;

	while (!cin.eof())
	{
		cin >> r.x >> r.y ;

		p.push_back(r); 
	}

	sort( p.begin(), p.end() );

	for ( int i = 0; i < p.size(); i++)
	{
		cout << "(" << p[i].x << "." << p[i].y << ")" << endl;
	}
}