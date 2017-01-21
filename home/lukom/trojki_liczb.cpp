#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;
class trojka{
	public:
	long long int a,b,c;
	void wypisz() const;
	bool prostokatna() const;
	bool trojkatna() const;

}T[1000];
bool trojka::trojkatna() const {
	if(a + b > c && a + c > b && b + c > a) return true;
	else return false;
}
bool trojka::prostokatna() const {
	if( a*a + b*b == c*c
	|| a*a + c*c == b*b
	|| b*b + c*c == a*a) return true;
	else return false;
}
void trojka::wypisz() const {
	cout<<a<<" "<<b<<" "<<c<<endl;
}
void wczytanie(){
	fstream plik;
	plik.open("../../zbior_zadan/66/trojki.txt");
	for(int i=0;i<1000;i++){
		plik >> T[i].a;
		plik >> T[i].b;
		plik >> T[i].c;
	}
}
int suma_cyfr(long long int l){
	int w = 0;
	while( l != 0){
		w += (l%10);
		l/=10;
	}
	return w;
}
bool pierwsza(long long int l){
	for(int i=2;i<=sqrt(l);i++){
		if((l%i)==0) return false;
	}
	return true;
}
void pyt1(){
	for(int i=0;i<1000;i++){
		if(suma_cyfr(T[i].a) + suma_cyfr(T[i].b) == T[i].c) T[i].wypisz();
	}
}
void pyt2(){
	for(int i=0;i<1000;i++){
		if(pierwsza(T[i].a) && pierwsza(T[i].b)
		&& T[i].c == T[i].a * T[i].b) T[i].wypisz();
	}
}
void pyt3(){
	for(int i=1;i<1000;i++){
		if(T[i].prostokatna() && T[i-1].prostokatna()){
			T[i-1].wypisz();
			T[i].wypisz();
			cout<<endl;
		}
	}
}
void pyt4(){
	int max=0;
	int ile=0;;
	for(int i=0;i<1000;i++){
		if(T[i].trojkatna())ile++;
		else{
			if(ile > max) max = ile;
			ile = 0;
		}
	}
	if(ile > max) max = ile;
	cout<<"dlugosc najdluzeszego ciagu trojkatnego: "<<max<<endl;
}
int main(){
	wczytanie();
//	pyt1();
//	pyt2();
//	pyt3();
//	pyt4();
}
