#include<iostream>
using namespace std;


class Liczba
{
	int n;
public:
	int getN()
	{
		return n;
	}
	
	void z_dwojkowego(string s)
	{
		int x = 0;
		int waga = 1;
		for(int i = s.length() - 1; i >= 0; i--)
		{
			if(s[i] == '1')
			{
				x = x + waga;
			}
			waga = waga * 2;
		}
		setN(x);
	}

	void setN(int y)
	{
		n = y;
	}

	string na_dwojkowy()
	{
		string q = "";
		int z = n;
		for(int i = 0; z > 0; i++)
		{
			if(z%2 == 0)
			{
				q = '0' + q;
				cout<<"parzysta";
			}
			if(z%2 != 0)
			{
				q = "1"  + q;
				cout<<"nieparzysta";
			}
			z = z/2;
		}
		return q;
	}



};

int main()
{
	string a;
	Liczba k;
	int liczba_parzystych;
	vector<Liczba> v;

	while(!cin.eof())
	{
		cin>>a;
		if(!cin.eof())
		{
			if(a[a.length() - 1] == 0)
			{
				liczba_parzystych += 1;
			}
			k.z_dwojkowego(a);
			v.push_back(k);
		}
		cout<<"liczba parzystych jest"<<endl<<liczba_parzystych<<endl;
	}

	int b;
	for(int i = 0; i < v.size(); i++)
	{
		if(v[i].getN()>b) b = v[i].getN();
	}
	cout<<"największa liczba"<<endl<<b<<endl;


	

}
