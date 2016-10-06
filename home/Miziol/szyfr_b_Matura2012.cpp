#include<iostream>

using namespace std;

int main()
{
	string j = "" , h = "", s = "";

	while ( cin >> j )
	{
		s = "";

		cin >> h;
		
		cout << "..." << j << " " << h << endl;
		
		for ( int i = 0; i < j.size(); i++)
		{
			int lj = (int) j[i], lh = (int) h[i%h.size()], ls = 0;
			ls = lj - lh + 64;
			if( ls < 65) ls = ls + 26;
			s = s + (char) ls;
		}
		cout << s << endl;
	}

}
