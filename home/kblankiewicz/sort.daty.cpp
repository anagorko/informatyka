#include<iostream>
#include<vector>
using namespace std;

class Data
{
	int d, m, r;
public:
	
	bool operator<(const Data& x) const
	{
		if(r > x.r) {return false}
		if(m > x.m) {return false}
		if(d > x.d) {return false}
		return true;
	}

	int getD()
	{
		return d;
	}
	int getM()
	{
		return m;
	}
	int getR()
	{
		return r;
	}

	void set(int a, int b, int c)
	{
		d = a;
		m = b;
		r = c;
	}
};

ostream& operator<<(ostream& s, Data y)
{
	s<<y.getD()<<" "<<y.getM()<<" "<<y.getR()<<endl;
	return s;
} 


istream& operator>>(istream& i, Data& y)
{
	int k, l, m;
	cin>>k>>l>>m;
	y.set(k, l, m);
	return i;
}


