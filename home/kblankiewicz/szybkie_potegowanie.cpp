#include <iostream>
using namespace std;

string na2( int n)
{
	string s = "";
	int t = n;
	int z = 0;
	while(t != 0)
	{
		if(t % 2 == 0) s = '0' + s;
		else s = '1' + s;
		t = t / 2;
	}
	return s;
}

int pot(int x, string k)
{
	int r = x;
	for(int i = 1; i < k.length(); i++)
	{
		if(k[i] == '1'){
			r = r * r * x;
		}else{
			r = r * r;
		}
	}
	return r;
}

int main()
{
	//cout << pot(2, "11") << endl;
	int x, k;
	cin >> x >> k;
	cout << pot(x, na2(k)) << endl;
}
