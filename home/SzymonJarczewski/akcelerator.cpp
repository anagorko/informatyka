#include <iostream>
using namespace std;

int main(){
	int n=0;		//liczba cząsteczek
	cin >> n;
	int t[n-1];		//kolejne prędkości cząstek
	for(int i=0; i<n; i++){		//wpisywanie do tablicy
		int j=0;		//liczba, która zaraz będzie wpisana
		cin >> j;
		t[i]=j;
	}
	int q;		//liczba zapytań
	cin >> q;
	for(; q>0; q--){
		int p=0;		//zapytanie
		cin >> p;
		int b=0;		//max indeks
		int a=0;		//min indeks
//wyznaczanie a
		int s=0;		//początek
		int e=n-1;		//koniec
		int x=(e+s)/2;		//sprawdzany min indeks
		for(int i=0; i<30; i++){
			if(t[x]>p){		//x jest za duży
				e=x-1;
				x=(e+s)/2;
			}
			if(t[x]<p){		//x jest za mały
				s=x+1;
				x=(e+s)/2;
			}
			if(t[x]==p){		//jeśli x został znaleziony
				if(x>0){
					if(t[x-1]<t[x]){
						a=x;
					}else{
						e=x-1;
						x=(e+s)/2;
					}
				}else{
					a=x;
				}
			}
		}
//wyznaczanie b
		int d=0;		//początek
		int r=n-1;		//koniec
		int y=(r+d)/2;		//sprawdzany max indeks
		for(int i=0; i<30; i++){
			if(t[y]>p){		//y jest za duży
				r=y-1;
				y=(r+d)/2;
			}
			if(t[y]<p){		//y jest za mały
				d=y+1;
				y=(r+d)/2;
			}
			if(t[y]==p){
				if(y<n-1){
					if(t[y]<t[y+1]){
						b=y;
					}else{
						d=y+1;
						y=(r+d)/2;
					}
				}else{
					b=y;
				}
			}
		}
		if(a==0 & b==0){
			if(t[0]==p){
				a=b-a+1;
				cout << a << endl;
			}else{
				cout << "0" << endl;
			}
		}else{
			a=b-a+1;
			cout << a << endl;
		}
	}
	return 0;
}
