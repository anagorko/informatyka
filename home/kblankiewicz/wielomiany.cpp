#include <iostream>
#include <vector>
using namespace std;


double max(int a, int b) //zwraca wieksza liczbe
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
	double getA(int n) const
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
			a.resize(n+1, 0.0);
			a[n]=x;
		}
	}

	int deg() const
	{
		int d;
		d=a.size();
		for (int i=d-1; i >= 0; i--)
			if(a[i] != 0)
				return i;
		return -1;
	}

	void print()
	{
		if(deg() == 0)
		{
			cout << "0";
		}
		int d;
		d = a.size();
		if(a[d-1] != 0) cout<<a[d-1]<<"x^"<<d-1;
		for(int i = d; i >= 2; i--)
		{
		    if(a[i-2] != 0)
		    cout<<" + "<<a[i-2]<<"x^"<<i-2;
		}
	}

	Polynomial& operator+=(const Polynomial &q)
	{
		if(deg()<q.deg())
		{
			a.resize(q.deg() + 1, 0.0);
		}

		for(int i = 0; i < a.size(); i++)
		{
			a[i] = a[i] + q.getA(i);
		}
		return *this;

	}
    	const Polynomial operator+(const Polynomial &q) const
	{
		Polynomial w (*this);
		w += q;
		return w;
	}

    	Polynomial& operator-=(const Polynomial &q)
	{
		if(deg()<q.deg())
		{
			a.resize(q.deg() + 1, 0.0);
		}

		for(int i = 0; i < a.size(); i++)
		{
			a[i] = a[i] - q.getA(i);
		}
		return *this;
	}
    	const Polynomial operator-(const Polynomial &q) const
	{
		Polynomial w (*this);
		w -= q;
		return w;
	}
	
    	/*Polynomial& operator*=(const Polynomial &q);
    	const Polynomial operator*(const Polynomial &q) const;
	*/

    	bool operator==(const Polynomial &q) const
	{
		if(deg() != q.deg())
		{
			return false;
		}

		for(int i = 0; i < deg(); i++)
		{
			if(a[i] != q.getA(i))
			{
				return false;
			}
		}
		return true;
	}
    	bool operator!=(const Polynomial &q) const
	{
		if(*this == q)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

};


Polynomial wiekszy(Polynomial q, Polynomial p) //zwraca wielomian wyzszego stopnia
{
	if(p.deg()>=q.deg())
		return p;
	else
		return q;
}

Polynomial mniejszy(Polynomial q, Polynomial p) //zwraca wielomian nizszego stopnia
{
	if(p.deg()<=q.deg())
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

Polynomial mult(Polynomial q, Polynomial p)
{
	Polynomial w;
    int h=0; //chwilowa wartoœæ w[i]
	for(int i = (q.deg()+p.deg()); i >= 0; i--)
    {
		for(int j = max(p.deg(), q.deg()); j >= 0; j--)
        {
            h=h+(wiekszy(p, q).getA(j)*mniejszy(p,q).getA(i-j));
        }
        w.setA(i, h);
        h=0;
    }
    return w;
}

Polynomial mult2(Polynomial p, double x) //mnozy wielomian przez liczbe
{
    Polynomial v;
    for(int i = 0; i <= p.deg(); i++)
        v.setA(i, p.getA(i)*x);
    return v;
}

double value(Polynomial p, double x)
{
    //wartoœæ w a = reszcie z p/(x-a)
    double m=p.getA(p.deg());
    for(int i = p.deg()-1; i >= 0; i--)
        m=m*x+p.getA(i);
    return m;
}

void div(Polynomial p, Polynomial q, Polynomial &wynik, Polynomial &reszta)
{
    int b = p.deg();
    Polynomial l;
    Polynomial prev_wynik;
    for(int i = b-q.deg(); p.deg() >= q.deg(); i--)
    {
        wynik.setA(i, p.getA(p.deg())/q.getA(q.deg()));
        l = mult(q, add(wynik, mult2(prev_wynik, -1)));
        p = add(p, mult2(l, -1));
        prev_wynik = wynik;
    }
    reszta = p;
}

int main()
{

	Polynomial p;

	p.setA(0,1);
	p.setA(1,5);
	p.setA(2,0);
	p.setA(3,3);
	/*p.setA(4,2);
	p.setA(5,2);
	p.setA(6,0);
	p.setA(7,0);*/

	p.print();
	cout<<endl<<p.deg()<<endl;

	Polynomial q;

	q.setA(0,0);
	q.setA(1,0);
	q.setA(2,0);
	q.setA(3,0);
	/*q.setA(4,0);
	q.setA(5,0);
	q.setA(6,0);
	q.setA(7,0);*/

	q.print();
	cout<<endl<<q.deg()<<endl;

	Polynomial w = p - q;
	w.print();

	/*
	cout<<endl<<"dodawanie; ";
	add(p, q).print();

    cout<<endl<<"mnozenie: ";
    mult(p, q).print();

    cout<<endl<<"wartosc p dla 2; ";
    cout<<value(p, 2);

    Polynomial wynik;
    Polynomial reszta;
    div(p, q, wynik, reszta);

    cout<<endl<<"DZIELENIE: "<<"wynik: ";
    wynik.print();
    cout<<"  reszta: ";
    reszta.print();*/
}
