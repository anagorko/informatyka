#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

class number
{
public:
	int dec;
	string bin;

	void setBin(string s)
	{
		dec =0;
		
		bin = s;
		
		for (int i = 0; i < bin.size(); i++ )
		{
			dec = dec * 2 + ( (int) s[i] - 48 );
		}
	}

};

int main()
{

	vector <number> base;

	number in;

	string s;

	int p = 0, max = 0, i9 = 0;

	for (int i = 0; i < 1000; i++)
	{
		cin >> s;
		in.setBin(s);
		base.push_back(in);
		if ( s[s.size() - 1] == '0' ) p++;
	}

	cout << "a) " << p << endl;

	for (int i = 1; i < 1000; i++)
	{
		if ( base[max].dec < base[i].dec ) max = i;
	}

	cout << "b) " << base[max].bin << " " << base[max].dec << endl;

	for (int i = 0; i < 1000; i++)
	{
		if ( base[i].bin.size() == 9 ) i9++;
	}

	cout << "c) ";
	
	bool out = false;

	for(int i = 1024; i > 0; i = i / 2)
	{
		if ( i9 >= i )
		{
			cout << "1";
			i9 = i9 - i;
			out = 1;
		}
		else if(out == 1)
		{
			cout << 0;
		}
	}

cout << endl;
}
