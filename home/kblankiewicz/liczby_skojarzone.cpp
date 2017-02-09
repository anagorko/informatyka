#include<vector>
#include<iostream>
#include<math.h>
using namespace std;

bool podzielna(int x, int y)
{
	float l = x;
	float d = y;
	float r = l / d;
	int _r;
	_r = (int)r;
	if(r == _r){
		return true;
	}
	else return false;
}

int suma_pierwiastkow(int x)
{
	int suma = 0;
	suma += 1;
	for(int i = 2; i * i <= x; i++)
	{
		if(podzielna(x, i)){
			suma += i;
			//cout << i << " ";	
			if(i * i != x)
			{
				suma += x / i;
				//cout << x / i << " ";
			}
		}
	}
	return suma;
}

int main()
{
	int q;
	cin >> q;
	//cout << endl << suma_pierwiastkow(q);
	
	if(suma_pierwiastkow(suma_pierwiastkow(q) - 1) == q + 1){
		cout << suma_pierwiastkow(q) - 1;
	}
	else{
	cout << "NIE" << endl;
	}
} 










