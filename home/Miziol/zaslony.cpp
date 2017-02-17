#include<iostream>
using namespace std;

double f( int x )
{
	return (x * x * x * x / 500.00) - (x * x / 200.00) - (3 / 250);
}

double g( int x )
{
	return -( (x * x * x / 30.00) + (x / 20) + (1 / 6) );
}

void podpunkt_a(double x_l, double x_p)
{
	double x = x_l, pole;

	int n = 1000; // dkładność obliczeń

	double x_przes = ((x_p - x_l) / n);

	for ( ; x < x_p; x = x + x_przes )
	{
		pole = pole + (x_przes * f( x )) - (x_przes * g( x ));
	}

	cout << "a) " << pole << endl;
}

int main()
{
	double y_g, y_d, x_l, x_p;
	y_g = 19.00 + (61.00 / 125.00);
	y_d = -32.00 - (2.00 / 3.00);
	x_l = 2.00;
	x_p = 10.00;

	podpunkt_a( x_l, x_p );
}