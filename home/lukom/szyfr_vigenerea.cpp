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
double indeks_koincydencji(string s){

	int il_wyst['Z' - 'A' + 1];
        for(int i=0;i<'Z'-'A'+1;i++) il_wyst[i]=0;
        for(int i=0;i<s.size();i++) il_wyst[s[i] - 'A']++;

	double k=0;
	int n=0;
	for(int i=0;i<'Z'-'A'+1;i++){
		n+=il_wyst[i];
		k += il_wyst[i] * (il_wyst[i] - 1);
	}
	k /= n * (n - 1);
	return k;
}
void wczytanie(){
	fstream plik;
	plik.open("../../zbior_zadan/77/dokad.txt");
	getline(plik, dokad);
	plik.close();
	plik.open("../../zbior_zadan/77/szyfr.txt");
	getline(plik, szyfr2, '\r');
	string smiec;
	getline(plik,smiec,'\n');
	getline(plik, klucz2, '\r');
	getline(plik, smiec, '\n');
	plik.close();
//	cout<<szyfr2<<endl;
//	cout<<klucz2<<endl;
//	cout<<klucz2.length()<<endl;
}
void pyt1(){
	cout<<"klucz musial byc powtorzony "<<powtorzenia_klucza(dokad, klucz1)<<" razy"<<endl;
	cout<<"zaszyfrowany tekst: "<<zaszyfrowany(dokad, klucz1)<<endl;
}
void pyt2(){
	cout<<szyfr2<<endl<<endl;
	cout<<"tekst odszyfrowany: "<<odszyfrowany(szyfr2, klucz2)<<endl;
}
void pyt3(){
//a)
	int il_wyst['Z' - 'A' + 1];
	for(int i=0;i<'Z'-'A'+1;i++) il_wyst[i]=0;
	for(int i=0;i<szyfr2.size();i++){
		il_wyst[szyfr2[i] - 'A']++;
	}
	for(int i=0;i<'Z'-'A'+1;i++){
		cout<<(char)(i+'A')<<": "<<il_wyst[i]<<endl;
	}
	cout<<endl;
//b)
	double d = 0.0285/(indeks_koincydencji(szyfr2) - 0.0385);
	cout<<"oszacowana dlugosc klucza: "<<d<<endl;
	cout<<"realna dlugosc klucza: "<<klucz2.length()<<endl;
}
int main(){
	wczytanie();
//	pyt1();
//	pyt2();
//	pyt3();
}
