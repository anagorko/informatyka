#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
class haslo {
	public:
	string s;
	bool tylko_cyfry() const;
	bool operator < (haslo h1) const;
	bool kolejne4znakiascii() const;
	bool znmldl() const;//znak numeryczny, mala litera, duza litera
};
bool haslo::znmldl() const {
	bool zn = false;
	bool ml = false;
	bool dl = false;
	for(int i=0;i<s.length();i++){
		if(s[i] >= '0' && s[i] <= '9') zn = true;
		else if(s[i] >= 'a' && s[i] <= 'z') ml = true;
		else if(s[i] >= 'A' && s[i] <= 'Z') dl = true;
	}
	return (zn && ml && dl)? true : false;
}
bool haslo::kolejne4znakiascii() const {
	for(int i=3;i<s.length();i++){
		if(s[i-3] + 1 == s[i-2] && s[i-2] + 1 == s[i-1]
		&& s[i-1] + 1 == s[i]) return true;
	}
	return false;
}
bool haslo::operator < (haslo h1) const {
	if(s < h1.s) return true;
	else return false;
}
bool haslo::tylko_cyfry() const {
	for(int i=0;i<s.length();i++) if(s[i] < '0' || s[i] > '9') return false;
	return true;
}
vector <haslo> H;
void wczytanie(){
	fstream plik;
	plik.open("../../zbior_zadan/74/hasla.txt");
	for(int i=0;i<200;i++){
		haslo h1;
		plik >> h1.s;
		H.push_back(h1);
	}
}
void pyt1(){
	int ile=0;
	for(int i=0;i<200;i++){
		if(H[i].tylko_cyfry()) ile++;
	}
	cout<<ile<<endl;
}
void pyt2(){
	sort(H.begin(), H.end());
	for(int i=1;i<H.size();i++){
		if(H[i].s == H[i-1].s){
			cout<<H[i].s<<endl;
			i++;
			while(i<H.size() && H[i].s == H[i-1].s) i++;
			i--;
		}
	}
}
void pyt3(){
	int ile = 0;
	for(int i=0;i<200;i++){
		if(H[i].kolejne4znakiascii()) ile++;
	}
	cout<<ile<<endl;
}
void pyt4(){
	int ile =0 ;
	for(int i=0;i<200;i++) if(H[i].znmldl())ile++;
	cout<<ile<<endl;
}
int main(){
	wczytanie();
//	pyt1();
//	pyt2();
//	pyt3();
//	pyt4();
}
