#include<iostream>
#include<vector>

using namespace std;

class Polynomial
{
	vector<double> p;

	private:

		int deg()
		{
			for(int i = p.size(); i > 0; i--)
			{
				if(p[i] > 0) return i-1;
				cout << "ERROR. NO VALUE. RETURNED -1\n";
				return -1;
			}
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
					cout << p[i] << (i == 0 ? "" : "*x^") << i+1 << " ";
				}

			}
			cout << endl;
		};

		double value(int n) // schemat Hornera
		{
			double value;
			value = p[deg()-1];
			for(int i = deg()-2; i >= 0; i--)
			{
				value = p[i] + (value * n);
			}

			return value;
		};

	Polynomial(int n)
	{
		p.resize(n);
	};

	Polynomial(int n, int v)
	{
		p.resize(n, v);
	};
};

int main()
{
	Polynomial p(10,0.0);

	p.setA(5,1);
	p.setA(4,3);

	cout << p.getA(4) << endl;

	p.print();

	cout << p.value(2) << endl;
}