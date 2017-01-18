#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;
class ciag{
	public:
	string s;
	bool cykliczny() const;
	bool obok11() const;
	int liczba() const;
	bool polpierwsza() const;
}C[1000];
bool pierwsza(int l){
	for(int i=2;i<sqrt(l);i++){
		if((l%i) == 0 ) return 0;
	}
	return 1;
}
bool ciag::polpierwsza() const {
	int l = liczba();
	for(int i=3;i<=sqrt(l);i++){
		if(!pierwsza(i)) continue;
		for(int j=3;j<=sqrt(l);j++){
			if(!pierwsza(j)) continue;
			if(i*j == l) return true;
			else if( i *j > l) break;
		}
	}
	return false;
}
int ciag::liczba() const {
	bool ujemna = false;
	int i=0;
	if(s[0] ==  '-'){
		ujemna = true;
		i=1;
	}
	int w = 0;
	for(;i<s.length();i++){
		w = w*2 + (int)s[i] - (int)'0';
	}
	if(ujemna) w*=-1;
	return w;
}
bool ciag::cykliczny() const {
	if((s.length()%2) != 0) return false;
	for(int i=0;i<s.length()/2;i++){
		if(s[i] != s[s.length()/2+i]) return false;
	}
	return true;
}
void wczytanie(){
	fstream plik;
	plik.open("../../zbior_zadan/63/ciagi.txt");
	for(int i=0;i<1000;i++) plik >> C[i].s;
	plik.close();
}
void pkt1(){
	for(int i=0;i<1000;i++) if(C[i].cykliczny()) cout<<C[i].s<<endl;
}
bool ciag::obok11() const{
	for(int j=1;j<s.length();j++) if(s[j] == '1' && s[j-1] == '1') return true;
	return false;
}
void pkt2(){
	int liczba = 0;
	for(int i=0;i<1000;i++) if(!C[i].obok11()) liczba++;
	cout<<"takich ciagow jest: "<<liczba<<endl;
}
void pkt3(){
	int ile=0;
	int najw = 0;
	int najm = 9999999;
	for(int i=0;i<1000;i++){
		if(C[i].polpierwsza()){
			ile++;
			if(C[i].liczba() > najw) najw = C[i].liczba();
			if(C[i].liczba() < najm) najm = C[i].liczba();
		}
	}
	cout<<"jest "<<ile<<" ciagow polpierwszych"<<endl;
	cout<<"najwieksza liczba: "<<najw<<endl;
	cout<<"najmniejsza liczba: "<<najm<<endl;
}
int main(){
	wczytanie();
//	pkt1();
//	pkt2();
//	pkt3();

}

