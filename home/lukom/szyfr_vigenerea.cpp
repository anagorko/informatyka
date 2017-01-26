#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
string dokad, szyfr2;
string klucz1 = "LUBIMYCZYTAC", klucz2;
string zaszyfrowany( string s, string k){
	int pk = -1;
	for(int i=0;i<s.length();i++){
		if(s[i] == ' ' || s[i] == ',' || s[i] == '.') continue;
		pk = (( pk + 1 )%k.length());
		s[i] = s[i] + k[pk] - 'A';
		if(s[i] > 'Z') s[i] -= 'Z' - 'A'+1;
	}
	return s;
}
string odszyfrowany( string s, string k){
	int pk = -1;
	for(int i=0;i<s.length();i++){
		if(s[i] == ' ' || s[i] == ',' || s[i] == '.') continue;
		pk = ( ( pk + 1 ) % k.length() );
		s[i] = s[i] - ( k[pk] - 'A' );
		if(s[i] < 'A') s[i] += 'Z' - 'A' +1;
	}
	return s;
}
int powtorzenia_klucza(string s, string k){
	return (s.length() % k.length() == 0)? s.length()/k.length() : s.length()/k.length()+1;
}
void wczytanie(){
	fstream plik;
	plik.open("../../zbior_zadan/77/dokad.txt");
	getline(plik, dokad);
	plik.close();
	plik.open("../../zbior_zadan/77/szyfr.txt");
	getline(plik, szyfr2);
	getline(plik, klucz2);
	plik.close();
//	cout<<szyfr2<<endl;
	cout<<klucz2<<endl;
	cout<<klucz2.length()<<endl;
}
void pyt1(){
	cout<<"klucz musial byc powtorzony "<<powtorzenia_klucza(dokad, klucz1)<<" razy"<<endl;
	cout<<"zaszyfrowany tekst: "<<zaszyfrowany(dokad, klucz1)<<endl;
}
void pyt2(){
	cout<<szyfr2<<endl<<endl;
	cout<<"tekst odszyfrowany: "<<odszyfrowany(szyfr2, klucz2)<<endl;
}
int main(){
	wczytanie();
//	pyt1();
//	pyt2();
}
