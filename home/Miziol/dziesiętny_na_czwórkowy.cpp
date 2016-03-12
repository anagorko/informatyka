#include<iostream>

using namespace std;

int pow(int p, int w)
{
	if(w==0) return 1;
	else if(w==1) return p;
	else
	{
		int rt = p;
		for(int i=2; i <= w; i++)
		{
			rt = rt * p; 
		}
		return rt;
	}
}

 int main()
 {
 	long long int n,w = 0,b,c;
 	cin >> n;

 	for (int i = 0; n!=0; i++)
 	{
 		b = n%4;
 		c = pow(10, i);
 		w = w + (c * b);
 		n = n / 4;
 		//cout << i << " " << n << " " << w << " " << c << " "  << b << " " << c - w << endl;
 	}

 	cout << w << endl;

 	return 0;
 }