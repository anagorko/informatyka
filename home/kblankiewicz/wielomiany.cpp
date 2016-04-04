#include <iostream>
#include <vector>
using namespace std;


double max(int a, int b)
{
	if(a > b)
		return a;
	else
		return b;
}	

class Polynomial
{
	vector<double> a;
 
public:
	double getA(int n)
	{
		if(n < a.size())
			return a[n];
		else
		{
			return 0;
		}
	}
	void setA(int n, double x)
	{
		if(n < a.size())
			a[n]=x;
		else
		{
			a.resize (n+1, 0.0);
			a[n]=x;
		}		
	}
	void print()
	{
		int d;
		d=a.size();
		for(int i = 0; i < d; i++)
			cout<<a[i]<<"x^"<<i<<" + ";
	}
	int deg()
	{
		int stopien;
		int d;		
		d=a.size();
		for (int i=d-1; i >= 0; i--)
			if(a[i] != 0)
				return i;
		return -1;		
	}
};

Polymonial compare+(Polynomial q, Polynomial p)	
{
	if(p.deg()>=q.deg())
		return p;
	else
		return q;
}

Polymonial compare-(Polynomial q, Polynomial p)	
{
	if(p.deg()>=q.deg())
		return p;
	else
		return q;
}

Polynomial add(Polynomial q, Polynomial p)
{
	int stW;
	stW = max(q.deg(), p.deg());
	Polynomial w;
	for(int i=0; i <= stW; i++)
	w.setA(i, p.getA(i)+q.getA(i));

	return w;
}

/*
	TO NIE JEST ZROBIONE
Polynomial mult(Polynomial q, Polynomial p)
{
	int stW;
	stW = max(q.deg(), p.deg());
	Polynomial w;
	for(int i=0; i <= (q.deg()+p.deg()); i++)
	{		//załóżmy parzystość
		for(int j=0; j <= max(p.deg(), q.deg()); j++)
			w.setA(i, compare+(p, q).getA(j)*compare-(p,q).getA(i-j))
		
	{	
}
*/
int main()
{
	Polynomial p;	
		
	p.setA(0,0);
	p.setA(1,0);
	p.setA(2,1);
	p.setA(3,8);
	p.setA(4,5);
	p.setA(5,0);
	p.setA(6,5);
	p.setA(7,0);

	p.print();
	cout<<endl<<p.deg()<<endl;

	Polynomial q;	
		
	q.setA(0,4);
	q.setA(1,7);
	q.setA(2,0);
	q.setA(3,6);
	q.setA(4,5);
	q.setA(5,0);
	q.setA(6,3);
	q.setA(7,2);

	q.print();
	cout<<endl<<q.deg()<<endl;

	add(p, q).print();
}

