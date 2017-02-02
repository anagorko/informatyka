#include<iostream>
#include<fstream>
#include<vector>
#include<iomanip>
using namespace std;
const int ILOSC  = 1876;
string T[ILOSC];
void wczytanie(){
	fstream plik;
	plik.open("../../zbior_zadan/73/tekst.txt");
	for(int i=0;i<ILOSC;i++){
		plik >> T[i];
	//	cout<<T[i]<<endl;
	}
}
bool kolejnetakiesame( string s ){
	for(int i=0;i<s.length()-1;i++) if(s[i] == s[i+1]) return true;
	return false;
}
bool spolgloska( char c ){
	string samogloski = "AEIOUY";
	for(int i=0;i<samogloski.length();i++) if(c==samogloski[i]) return false;
	return true;
}
void pyt1(){
	int ile=0;
	for(int i=0;i<ILOSC;i++){
		if(kolejnetakiesame(T[i]))ile++;
	}
	cout<<"wyrazow gdzie 2 litery po kolei sa takie same: "<<ile<<endl;
}
void pyt2(){
	int ilosc_liter = 0;
	int dlugosc_alfabetu = 'Z' - 'A'+1;
	int wystepowanie[dlugosc_alfabetu];
	for(int i=0;i<dlugosc_alfabetu;i++) wystepowanie[i] = 0;
	for(int i=0;i<ILOSC;i++){
		for(int j=0;j<T[i].length();j++){
			ilosc_liter++;
			wystepowanie[(int)T[i][j] - 'A']++;
		}
	}
	for(int i=0;i<dlugosc_alfabetu;i++){
		cout<<fixed<<setprecision(2);
		cout<< (char)(i+'A')<<" : "<<wystepowanie[i]<<" ("<<(float)(100*wystepowanie[i])/ilosc_liter<<"%)"<<endl;
	} 
}
void pyt3(){
	int najdluzsze=0;
	int dlugosc = 0;
	for(int i=0;i<ILOSC;i++){
		int pocz = 0,kon = 0;
		while(true){
			while(pocz < T[i].length() && !spolgloska(T[i][pocz])) pocz++;
			kon = pocz;
			while(kon < T[i].length() && spolgloska(T[i][kon])) kon++;
			if(dlugosc < kon-pocz + 1){
				dlugosc = kon-pocz+1;
				najdluzsze = i;
			}
			pocz = kon;
			if(kon >= T[i].length()-1) break;
		}
	}
	cout<<"dlugosc : "<<dlugosc<<endl;
	cout<<"pierwsze o takiej dlugosci : "<<T[najdluzsze]<<endl;
	int ile=0;
	for(int i=0;i<ILOSC;i++){
                int pocz = 0,kon = 0;
                while(true){
                        while(pocz < T[i].length() && !spolgloska(T[i][pocz])) pocz++;
                        kon = pocz;
                        while(kon < T[i].length() && spolgloska(T[i][kon])) kon++;
                        if(dlugosc == kon-pocz + 1) ile++;
			pocz = kon;
                        if(kon >= T[i].length()-1) break; 
                }
        }
	cout<<"jest "<<ile<<" wyrazow o takiej dlugosci"<<endl;
}
int main(){
	wczytanie();
//	pyt1();
//	pyt2();
//	pyt3();
}
