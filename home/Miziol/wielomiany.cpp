#include<iostream>
#include<vector>

using namespace std;

class Polynomial
{
	vector<double> p;

	public:

		int deg()
		{
			int max = -1;
			for (int i = 0; i < p.size(); i++)
			{
				if(p[i] != 0.0) max = i;
			}
			return max;
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
			for(int i = p.size()-1; i > 0; i--)
			{
				if(p[i] != 0 || c == true)
				{
					c = true;
					cout << p[i] << "*x^" << i << " + ";
				}

			}

			cout << p[0] << endl;
		};

		double value(int n) // schemat Hornera
		{
			double value;
			value = 0;
			for(int i = deg()+1; i >= 0; i--)
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

			p.resize(n+1);

			for(int i = 0; i <= n; i++)
			{
				p[i] = 0;
			}

			for(int i = 0; i <= n; i++)
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

			p.resize(n+1);

			for(int i = 0; i <= n; i++)
			{
				p[i] = 0;
			}

			for(int i = 0; i <= n; i++)
			{
				p[i] = a.getA(i) - b.getA(i);
			}
		};

		void multiply(Polynomial a, Polynomial b) // c = a * b
		{
			int n = a.deg() + b.deg();
			int r;

			if(a.deg() > b.deg())
			{
				r = a.deg();
			}else{
				r = b.deg();
			}

			p.resize(n+1);

			for(int i = 0; i <= n; i++)
			{
				p[i] = 0;
			}

			p[0] = a.getA(0) + b.getA(0);

			for(int i = 1; i <= n; i++)
			{
				for(int j = 0; j <= i; j++)
				{
					p[i] = p[i] + (a.getA(j) * b.getA(i-j));
				}
			}
		};



		void div(Polynomial a, Polynomial b, Polynomial &r) // c + r = a / b
		{
			int n = a.deg() - b.deg();

			p.resize(n+1);

			for(int i = 0; i <= n; i++)
			{
				p[i] = 0;
			}

			for(int i = 0; i <= r.deg(); i++)
			{
				r.setA(i, 0.0);
			}

			if (b.deg() > a.deg())
			{
				cout << "ERROR\n ";
				return;
			}

			for(int i = a.deg() + 1; i >= 0; i = a.deg())
			{
				if(i < b.deg())
				{
					break;
				}

				p[i - b.deg()] = a.getA(i) / b.getA(b.deg());

				for(int j = b.deg(); j >= 0; j--)
				{
					a.setA(j + i - b.deg(), p[i - b.deg()] * b.getA(j));
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

	p.setA(3,1);
	p.setA(2,3);
	p.print();

	Polynomial q(10,0.0);

	q.setA(2,2);
	q.setA(1,6);
	q.print();

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

	Polynomial x(10,0.0);

	x.div(p,q,z);

	x.print();
	cout << endl;
	z.print();
	cout << endl;

}