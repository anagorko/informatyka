#include<iostream>
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

	string az()
	{
		return a;
	}

	void set(string in)
	{
		s = in;

		a = abc(s);
	}

	/*anagram operator== ()
	{

	}*/

	/*anagram operator= ()
	{

	}*/
};


	
int main()
{
	vector <anagram> dictionary;

	anagram in;

	string s;

	while(true)
	{
		getline(cin, s);
		if(s == " ") break;
		in.set(s);
		dictionary.push_back(in);
	}

	//cd nastapi

}