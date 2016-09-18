#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class data
{

public:
	int dd,mm,rrrr;

	bool operator == (const data& b)
	{
		return (dd == b.dd && mm == b.mm && rrrr == b.rrrr);
	}

	bool operator < (const data& b)
	{
		if(rrrr < b.rrrr) return true;
		if(rrrr == b.rrrr && mm < b.mm) return true;
		if(rrrr == b.rrrr && mm == b.mm && dd < b.dd) return true;

		return false;
	}

	bool operator > (const data& b)
	{
		if(rrrr > b.rrrr) return true;
		if(rrrr == b.rrrr && mm > b.mm) return true;
		if(rrrr == b.rrrr && mm == b.mm && dd > b.dd) return true;

		return false;
	}
};

int main()
{
	vector <data> base;

	data r;

	while(!cin.eof())
	{
		cin >> r.dd >> r.mm >> r.rrrr;
		base.push_back(r);
	}

	sort ( base.begin(), base.end() );
}