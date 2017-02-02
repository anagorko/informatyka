#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
vector <string> szyfr1, szyfr2, szyfr3;
vector <int> klucz1, klucz2, klucz3;
string zaszyfrowany( string s, vector <int> klucz){
	if(s.length() < klucz.size()) cout<<"WARNING"<<endl;
	for(int i=0;i<s.length();i++){
		char z = s[i];
		s[i] = s[ klucz[i%klucz.size()] - 1];
		s[ klucz[i%klucz.size()] - 1] = z;
	}
	return s;
}
string odszyfrowany( string s, vector <int> klucz){
	for(int i=s.length()-1;i>=0;i--){
		char z = s[i];
                s[i] = s[ klucz[i%klucz.size()] - 1];
                s[ klucz[i%klucz.size()] - 1] = z;
	}
	return s;
}
void wczytanie(){
	fstream plik;
	plik.open("../../zbior_zadan/76/szyfr1.txt");
	for(int i=0;i<6;i++){
		string s;
		plik >> s;
		szyfr1.push_back(s);
	}
	for(int i=0;i<50;i++){
		int l;
		plik >> l;
		klucz1.push_back(l);
	}
	plik.close();
	plik.open("../../zbior_zadan/76/szyfr2.txt");
	string s;
	plik >> s;
	szyfr2.push_back(s);
	for(int i=0;i<15;i++){
		int l;
		plik >> l;
		klucz2.push_back(l);
	}
	plik.close();
	plik.open("../../zbior_zadan/76/szyfr3.txt");
	plik >> s;
	szyfr3.push_back(s);
	int t[] = {6, 2, 4, 1, 5, 3};
	for(int i=0;i<6;i++) klucz3.push_back(t[i]);
}
void pyt1(){
	for(int i =0;i<szyfr1.size();i++){
		cout<<zaszyfrowany(szyfr1[i], klucz1)<<endl;
	}
}
void pyt2(){
	cout<<zaszyfrowany(szyfr2[0], klucz2)<<endl;
}
void pyt3(){
	cout<<odszyfrowany(szyfr3[0], klucz3)<<endl;

}
int main(){
	wczytanie();
//	pyt1();
//	pyt2();
//	pyt3();

}
