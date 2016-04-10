#include<iostream>
#include<vector>

using namespace std;

class Polynomial
{
	vector<double> p;

	public:

		int deg()
		{
			for(int i = p.size(); i > 0; i--)
			{
				if(p[i] != 0) return i-1;
			}
			cout << "ERROR. NO VALUE. RETURNED -1\n";
			return -1;
		};

	public:
		double getA(int n)
		{
			if(n > deg())
			{
				return 0;
			}else{
				return p[n];
			}
		};

		void setA(int n, double a)
		{
			if(p.size() < n) p.resize(n+1,0.0);

			p[n] = a;
		};

		void print()
		{
			bool c = false;
			for(int i = p.size()-1; i >= 0; i--)
			{
				if(p[i] != 0 || c == true)
				{
					c = true;
					cout << p[i] << "*x^" << i+1 << " + ";
				}

			}

			cout << p[0] << endl;
		};

		double value(int n) // schemat Hornera
		{
			double value;
			value = 0;
			for(int i = deg()-2; i >= 0; i--)
			{
				value = p[i] + (value * n);
			}

			return value;
		};

		void add(Polynomial a, Polynomial b) // c = a + b
		{
			int n;
			if(a.deg() > b.deg())
			{
				n = a.deg();
			}else{
				n = b.deg();
			}

			p.resize(n, 0.0);

			n--;

			for(int i = 0; i < n; i++)
			{
				p[i] = a.getA(i) + b.getA(i);
			}
		};

		void substraction(Polynomial a, Polynomial b) // c = a - b
		{
			int n;
			if(a.deg() > b.deg())
			{
				n = a.deg();
			}else{
				n = b.deg();
			}

			p.resize(n, 0.0);

			n--;

			for(int i = 0; i < n; i++)
			{
				p[i] = a.getA(i) - b.getA(i);
			}
		};

		void multiply(Polynomial a, Polynomial b) // c = a * b
		{
			int n = a.deg() + b.deg();

			p.resize(n, 0.0);

			cout << a.deg() << b.deg() << n << endl;

			n--;

			for(int i = 0; i < n; i++)
			{
				for(int j = 0; j < n; j++)
				{
					p[i] = p[i] + a.getA(i) * b.getA(i-j);
				}
			}

		};




		//konstruktory 

	Polynomial()
	{
		p.resize(1000);

		for(int i = 0; i < 1000; i++)
		{
			p[i] = 0.0;
		}
	};

	Polynomial(int n)
	{
		p.resize(n);

		for(int i = 0; i < n; i++)
		{
			p[i] = 0.0;
		}
	};

	Polynomial(int n, double v)
	{
		p.resize(n);

		for(int i = 0; i < n; i++)
		{
			p[i] = v;
		}
	};
};






int main()
{
	Polynomial p(10);

	p.setA(5,1);
	p.setA(4,3);
	p.print();
	cout << p.deg() << " " << p.value(2) << endl << endl;

	Polynomial q(10,0.0);

	q.setA(5,2);
	q.setA(4,6);
	q.print();
	cout << q.deg() << " " << q.value(2) << endl << endl;;

	Polynomial z;

	z.add(p,q);
	z.print();
	cout << endl;

	z.substraction(p,q);
	z.print();
	cout << endl;

	z.multiply(p,q);
	z.print();
	cout << z.deg() << endl;
	cout << endl;

}