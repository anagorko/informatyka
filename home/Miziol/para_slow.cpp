#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool palindrom(string s)
{
	//cout << s.size() << endl;

	for ( int i = 0; i * 2 < s.size(); i++)
	{
		//cout << s[i] << " " << s[s.size() - 1 - i] << endl;
		if ( s[i] != s[s.size() - 1 - i] ) return false;
	}
	return true;
}

bool a_in_b(string f, string s)
{
	for ( int i = 0; i <= (f.size() - s.size()); i++)
	{
		if( f[i] == s[0])
		{
			bool cor = true;
			for (int j = 1; j < s.size(); j++)
			{
				if ( f[i+j] != s[j] )
				{
					cor = false;
					break;
				}
			}
			if( cor == true ) return true;
		}
	}
	return false;
}

bool a_with_b(string a, string b, bool aba)
{
	if (aba == true) return false;

	for ( int i = 1; i < b.size(); i++)
	{
		if ( b[i] == a[0] )
		{
			for( int j = i + 1; j < b.size(); j++)
			{
				if ( a[j - i] != b[j] ) break;
				if ( a[j - i] == b[j] && j == (b.size() - 1)) return true;
			}
		}	
	}

	for ( int i = b.size() - 2; i >= 0; i--)
	{
		if( b[i] == a[a.size() - 1] )
		{
			for ( int j = i - 1; j >= 0; j--)
			{
				if ( a[a.size() - b.size() + j] != b[j] ) break;
				if ( a[a.size() - b.size() + j] == b[j] && j == 0) return true;
			}
		}
	}
	
	return false;
}

class word
{
public:

	string a,b;

	bool pal_a, pal_b, aba, ab_ba;

	void 	to_do()
	{
		pal_a = palindrom(a);
		pal_b = palindrom(b);
		aba = a_in_b(a, b);
		ab_ba = a_with_b(a, b, aba);
	}

};

int main()
{
	vector <word> base;

	word i;

	string in;

	int pal=0, aba=0, ab_ba=0;

	while ( cin >> in )
	{
		i.a = in;

		cin >> in;

		i.b = in;

		i.to_do();

		base.push_back(i);
	}

	for ( int i = 0; i < base.size(); i++)
	{
		if ( base[i].pal_a == true) pal++;
		if ( base[i].pal_b == true) pal++;
		if ( base[i].aba == true) aba++;
		if ( base[i].ab_ba == true) ab_ba++;
	}

	cout << "a) " << pal << endl;
	cout << "b) " << aba << endl;
	cout << "c) " << ab_ba << endl;

}
