#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
int L[2][1000];
int z_systemu(int l, int b){
	int w=0;
	int mn=1;
	while(l!=0){
		w += (l%10)*mn;
		mn*=b;
		l/=10;
	}
	return w;
}
int na_system(int l, int b){
	int w=0;
	int mn=1;
	while(l!=0){
		w += (l%b)*mn;
		mn*=10;
		l/=b;
	}
	return w;
}
void wczytanie(){
	fstream plik;
	plik.open("../../zbior_zadan/62/liczby1.txt");
	for(int i=0;i<1000;i++){
		int l;
		plik >> l;
		L[0][i] = z_systemu(l, 8);
	}
	plik.close();
	plik.open("../../zbior_zadan/62/liczby2.txt");
	for(int i=0;i<1000;i++) plik >> L[1][i];
	plik.close();
}
void pkt1(){
	int najw = 0;
	int najm = 99999;
	for(int i=0;i<1000;i++){
		if(L[0][i] < najm) najm = L[0][i];
		if(L[0][i] > najw) najw = L[0][i];
	}
	cout<<"najmniejsza liczba to: "<<na_system(najm, 8)<<endl;
	cout<<"najwieksza liczba to: "<<na_system(najw, 8)<<endl;
}
void pkt2(){
	int nr_p = 0;
	int dlugosc_ciagu = 1;
	int mnr = 0;
	int mdl = 0;
	for(int i=1;i<1000;i++){
		if(L[1][i] < L[1][i-1]){
			if(dlugosc_ciagu > mdl){
				mdl = dlugosc_ciagu;
				mnr = nr_p;
			}
			nr_p = i;
			dlugosc_ciagu = 0;
		}
		dlugosc_ciagu++;
	}
	cout<<"nadluzyszy ciag niemalejacy zaczyna sie od "<<L[1][mnr]<<" i ma dlugosc "<<mdl<<endl;

}
void pkt3(){
	int tsw = 0;
	int ww1 = 0;
	for(int i =0;i<1000;i++){
		if(L[0][i] == L[1][i]) tsw++;
		else if( L[0][i] > L[1][i]) ww1++;
	}
	cout<<"ma taką samą wartość: "<<tsw<<" wierszy"<<endl;
        cout<<"liczby1.txt maja wieksza wartość: "<<ww1<<" wierszy"<<endl;

}
void pkt4(){
	int os6 = 0;
	int dz6 = 0;
	for(int i=0;i<1000;i++){
		int os = na_system(L[1][i], 8);
		int dz = L[1][i];
		while(os !=0){
			if(os % 10 == 6)os6++;
			os/=10;
		}
		while(dz != 0){
			if(dz % 10 == 6)dz6++;
			dz/=10;
		}
	}
	cout<<"w liczby2 cyfra 6 wystepuje "<<dz6 <<" razy"<<endl;
	cout<<"gdyby zapisać te liczby w systemie osemkowym to 6 by było "<<os6<<endl;

}
int main(){
	wczytanie();
//	pkt1();
//	pkt2();
//	pkt3();
//	pkt4();
}
