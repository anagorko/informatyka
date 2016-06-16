#include<iostream>
#include<string>
#include<cmath>

using namespace std;

string code(string s, int k)
{
	for (int i = 0; i < s.size(); i++)
	{
		s[i] = (s[i] + (k % 26));
		if ( (int)s[i] > 90) s[i] = (s[i] % 90) + 64;
	}
	return s;
}

string ucode(string s, int k)
{
	for (int i = 0; i < s.size(); i++)
	{
		s[i] = (s[i] + (k % 26));
		if ( (int)s[i] < 65) s[i] = s[i] + 26;
	}
	return s;
}

int main()
{
    
	string s[3000][2];
	int sk[3000];
	int k;

	//6.1

	/*cout << "\n\n";
	k=107;
	for (int i = 0; i < 100; i++)
	{
		cin >> s[i][0];
	}

	cout << endl;

	for (int i = 0; i < 100; i++)
	{
		s[i][0] = code(s[i][0], k);
		cout << s[i][0] << endl;
	}*/

	//6.2 dla 100 pierwszych przypadków

	/*cout << "\n\n";
	for (int i = 0; i < 100; i++)
	{
		cin >> s[i][0] >> sk[i];
	}

	cout << endl;

	for (int i = 0; i < 100; i++)
	{
		k = - sk[i];
		s[i][0] = ucode(s[i][0], k);
		cout << s[i][0] << endl;
	}*/

	//6.3

	cout << "\n\n";
	for (int i = 0; i < 3000; i++)
	{
		cin >> s[i][0] >> s[i][1];
	}

	cout << endl;

	for (int i = 0; i < 3000; i++)
	{
		k = (((int)s[i][0][0] - 65) - ((int)s[i][1][0] - 65) + 26) % 26;
		s[i][0] = code(s[i][0], k);
		if (s[i][0] != s[i][1]) cout << ucode(s[i][0], -k) << endl;
	}

}