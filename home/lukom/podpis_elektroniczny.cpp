#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
string W[11];
int P[11][8];
string uzupelniony_kropkami(string s){
	for(int i=0;i< (s.length()%8);i++) s += ".";
	return s;
}
string skrot(string wiadomosc){
	string S = "ALGORYTM";
	wiadomosc = uzupelniony_kropkami(wiadomosc);
	for(int i=0;i<wiadomosc.length();i++){
		S[i%8] = ( (S[i%8] + wiadomosc[i])%128);
	}
	string wynik="";
	for(int i=0;i<8;i++) wynik = wynik + (char)(65 + (S[i]%26));
	return wynik;
}
string Adeszyfrowany(int wiadomosc[8], int d, int n){
	string x="";
	for(int i=0;i<8;i++){
		x += ( (wiadomosc[i]*d)%n );
	}
	return x;
}
void wczytanie(){
	fstream plik;
	plik.open("../../zbior_zadan/78/wiadomosci.txt");
	for(int i=0;i<11;i++){
		getline(plik, W[i], '\r');
		string trash;
		getline(plik,trash);
	}
	plik.close();
	plik.open("../../zbior_zadan/78/podpisy.txt");
	for(int i=0;i<11;i++){
		for(int j=0;j<8;j++){
			plik >> P[i][j];
		}
	}
}

void pyt1(){
	for(int i=0;i<11;i++){
		cout<<W[i].length()<<" - > "<<uzupelniony_kropkami(W[i]).length()<<"\n";
		string wiadomosc = skrot(W[i]);
		for(int j=0;j<wiadomosc.length();j++) cout<<(int)wiadomosc[j]<<" ";
		cout<<"\n";
		cout<<wiadomosc<<"\n\n";
	}
}
void pyt2(){
	for(int i=0;i<11;i++){
		for(int j=0;j<8;j++) cout<<P[i][j]<<" ";
		cout<<"\n"<<Adeszyfrowany(P[i],3,200)<<"\n";
	}
}
void pyt3(){
	for(int i=0;i<11;i++){
		cout<<Adeszyfrowany(P[i],3,200)<<"\n";
		cout<<skrot(W[i])<<"\n";
		if(Adeszyfrowany(P[i],3,200) == skrot(W[i])) cout<<"TAK\n\n";
		else cout<<"NIE \n\n";
	}
}
int main(){
	wczytanie();
//	pyt1();
//	pyt2();
//	pyt3();
}
