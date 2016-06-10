#include <iostream>

using namespace std;

int main(){
	int z;
	cin >> z;		//ilość zagadek
	for(;z>0;z--){
		long long int p;		//współczynnik c
		cin >> p;
		long long int q;		//wynik
		cin >> q;
		long long int s=0;		//początek
		long long int e=q;		//koniec
		long long int x=(e+s)/2;		//x
		for(int m=0; m<22; m++){
			if(x^3+p*x<q){		//jeśli x jest za mały
				e=x-1;
			}
			if(x^3+p*x>q){		//jeśli x jest za duży
				s=x+1;
			}
			if(x^3+p*x==q){		//jeśli x jest rozwiązaniem
				cout << x << endl;
				break;
			}
			if(m==21){		//jeśli x nie istnieje rozwiązanie całkowite
				cout << "NIE" << endl;
			}
		}
	}
	return 0;
}
