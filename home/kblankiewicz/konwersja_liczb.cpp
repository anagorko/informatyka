#include <iostream>
#include <cmath>
using namespace std;

string q = "0123456789ABCDEF";

char szukaj(int z)
{
	return q[z];
}

string nasystem(int n, int b)
{	
	string s = "";
	int np = abs(n);
	int z;
	while(np != 0)
	{
		z = np % b;
		s = szukaj(z) + s;
		np = np/b;
	}
	if(n >=0)
	{
		return s;
	}
	else
	{
		string v = "-" + s;
		return v;
	}
}

int zsystemu(string d, int b)
{
	string s;
	if(d[0] != '-'){
		s = d;
	}
	else{
		cout<<"s"<<s;
		for(int i = 1; i < d.length(); i++){
			s = s + d[i];
		}
	}
	cout<< s <<endl;
	int x = 0;
	for(int i = 0; i < s.length(); i++)
	{
		for(int j = 0; j < 16; j++)
		{
			if(s[i] == q[j])
			{
				x = x * b;
				x = (x + j);
				break;
			}
		}
	}
	if(d[0] != '-'){
		return x;
	}
	else{
		return -x;
	}
}


int main()
{

int n;
int b;
int c;
string t;
cout << "na system" << endl;
cin >> n >> b;
cout << nasystem(n, b) << endl;

cout << "z systemu" << endl; 
cin >> t ;
cin >> c;
cout << zsystemu(t, c);

}
