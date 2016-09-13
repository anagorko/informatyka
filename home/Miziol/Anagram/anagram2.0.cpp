#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

string abc(string s)
{
	string w = "";
	for (int i = 97; i <= 122; i++)
	{
		for (int j = 0; j < s.size(); j++)
		{
		if( (int) s[j] == i ) w = w + (char)i;
		}
	}

	return w;
}

class anagram
{
	string s;
	string a;

public:

	string word()
	{
		return s;
	}

	string az() const
	{
		return a;
	}

	void set(string in)
	{
		s = in;

		a = abc(s);
	}

	bool operator==(const anagram& a) const
	{
		return az() == a.az();
	}

};


	
int main()
{
	vector <anagram> dictionary;

	anagram in;

	string s = "";

	while(!cin.eof())
	{
		getline(cin, s);
		in.set(s);
		dictionary.push_back(in);
	}

	sort( dictionary.begin(), dictionary.end() );

	s = "";

	for (int i = 0; i < dictionary.size(); i++)
	{
		if( s == dictionary[i].az())
		{
			; 	//dictionary[i].az()
		}
	}

}