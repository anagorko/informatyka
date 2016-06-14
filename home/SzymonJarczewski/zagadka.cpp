#include <iostream>

using namespace std;

int main(){
	int z=0;
	cin >> z;		//ilość zagadek
	for(;z>0;z--){
		unsigned long long int p;		//współczynnik c
		cin >> p;
		unsigned long long int q;		//wynik
		cin >> q;
		unsigned long long int s=0;		//początek
		unsigned long long int e=100000;		//koniec
		unsigned long long int x=(e+s)/2;		//x
		for(int m=0; m<2000; m++){
			if(x*x*x+p*x<q){		//jeśli x jest za mały
				s=x+1;		//początek przesuwamy za x
				x=(e+s)/2;
			}
			if(x*x*x+p*x>q){		//jeśli x jest za duży
				e=x-1;		//koniec przesuwamy za x
				x=(e+s)/2;
			}
			if(x*x*x+p*x==q){		//jeśli x jest rozwiązaniem
				cout << x << endl;
				break;
			}
			if(m==1999){		//jeśli nie istnieje rozwiązanie całkowite
				cout << "NIE" << endl;
			}
		}
	}
	return 0;
}
