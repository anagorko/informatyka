#include<iostream>
#include<math.h>

using namespace std;

 int main()
 {
 	int n,w = 0,b,c;
 	cin >> n;

 	for (int i = 0; n!=0; i++)
 	{
 		b = n%4;
 		c = pow(10, i);
 		w = w + (c * b);
 		n = n / 4;
 		cout << i << " " << n << " " << w << " " << pow(10, i) << " "  << b << " " << c - w << endl;
 	}

 	cout << w << endl;

 	return 0;
 }