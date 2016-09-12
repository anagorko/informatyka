#include<iostream>
#include<vector>
using namespace std;

string anagram(string s)
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

int main()
{
	string in = " ";
	bool out;
	vector <string> s;

	while (in != "aaa")
	{
		cin >> in;
		s.push_back(in);

	}

	for (int i = 0; i < s.size(); i++)
	{
		out = 0;
		for (int j = i + 1; j < s.size(); j++)
		{
			if(i>j) break;
			if( anagram(s[i]) == anagram(s[j]) )
			{
				if (out == false) cout << s[i] << " ";
				out = true;
				cout << s[j] << " ";
			}
		}
		cout << endl;
	}

}