#include<iostream>
#include<vector>
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
			}
			if(z%2 != 0)
			{
				q = '1'  + q;
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
	int liczba_parzystych = 0;
	int liczba_9 = 0;
	int suma_9 = 0;
	vector<Liczba> v;

	while(!cin.eof())
	{
		cin>>a;
		if(!cin.eof())
		{
			if(a[a.length() - 1] == '0')
			{
                liczba_parzystych += 1;
			}
			k.z_dwojkowego(a);
			v.push_back(k);
			if(a.length() == 9)
            {
                liczba_9 += 1;
                suma_9 += k.getN();
            }
		}
	}
    cout<<"liczba parzystych:"<<endl<<liczba_parzystych<<endl;


	int b = 0;
	int i2 = 0;
	for(int i = 0; i < v.size(); i++)
	{
		if(v[i].getN()>b)
        {
            b = v[i].getN();
            i2 = i;
        }
	}

    cout<<"kontrola";
	cout<<"największa liczba"<<endl<<b<<" = "<<v[i2].na_dwojkowy()<<endl;

    cout<<"jest "<<liczba_9<<" liczb dziewięciocyfrowych"<<endl<<"ich suma to: "<<suma_9;
}
