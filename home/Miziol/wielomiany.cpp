#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

class Polynomial
{
	vector<double> p;

	public:

		int deg()
		{
			int max = -1;
			for (unsigned int i = 0; i < p.size(); i++)
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

		void setA(unsigned int n, double a)
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

			if (b.deg() > a.deg())
			{
				cout << "ERROR\n ";
				return;
			}

			int n = a.deg() - b.deg();

			p.resize(n+1);

			//zerowaanie

			for(int i = 0; i <= n; i++)
			{
				p[i] = 0;
			}

			for(int i = 0; i <= r.deg(); i++)
			{
				r.setA(i, 0.0);
			}

			//zerowanie - koniec

			for(int i = a.deg(); i >= 0; i--)
			{
				if(b.getA(b.deg()) != 0)
				{
					p[i-b.deg()] =+ a.getA(i) / b.getA(b.deg());

					for (int j = 1; j < b.deg() - 1; j--)
					{
						if(b.getA(b.deg()-1-j) != 0)
						{
							a.setA(i-j, a.getA(i-j) / b.getA(b.deg() - 1 - j));
						}
					}
				}
			}

			return;
		};

		bool checkRoot(double r)
		{
			double w = 0;

			for(int i = deg(); i >= 0; i--)
			{
				w =+ p[i] * pow(r, i);
			}

			if(w == 0) return 1;
			return 0;

		};



		void roots()
		{
			int l= 1, q= 1;

			if(checkRoot(0)) cout << "0" << endl;

			for( int i = 0; i < deg(); i++)
			{
				if( p[i] != (int)p[i]) return;
			}

			for( ; q < p[deg()]; q++)
			{
				if( (int) p[deg()]%q == 0 && checkRoot(q) ) cout << q << endl;
				if( (int) p[deg()]%q == 0 && checkRoot(-q) ) cout << -q << endl;

			}

			q=1;

			for( ; l < p[0]; l++)
			{
				if( (int) p[0]%l == 0 && checkRoot(l) ) cout << l << endl;
				if( (int) p[0]%l == 0 && checkRoot(-l) ) cout << -l << endl;

			}

			l=1;

			for( ; l < p[deg()]; l++)
			{
				for( ; q <= p[0]+1; q++)
				{
					if(checkRoot(l/q)) cout << l/q << endl;
					if(checkRoot(-l/q)) cout << -l/q << endl;
				}

			}

			return;
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

	Polynomial x(10,0.0);

	x.div(p,q,z);

	x.print();
	cout << endl;
	z.print();
	cout << endl;

	x.roots();

	cout << "\n\n\n";

	p.roots();

	return 0;

}
