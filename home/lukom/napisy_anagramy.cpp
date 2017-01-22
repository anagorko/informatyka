#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
class para {
	public:
	string a,b;
	void wypisz() const;
}P[1000];
void para::wypisz() const {
	cout<<a<<" "<<b<<endl;
}
bool jednolita( string s ) {
	for(int i=0;i<s.length();i++) if(s[i] != s[0]) return false;
	return true;
}
bool anagramy( string a, string b){
	if(a.length() != b.length()) return false;
	for(int i=0;i<a.length();i++){
		bool znalazlem = false;
		for(int j=0;j<b.length();j++){
			 if(a[i] == b[j]){
				b[j] = 0;
				znalazlem = true;
				break;
			}
		}
		if(!znalazlem) return false;
	}
	return true;
}
void wczytanie(){
	fstream plik;
	plik.open("../../zbior_zadan/68/dane_napisy.txt");
	for(int i=0;i<1000;i++){
		plik >> P[i].a;
		plik >> P[i].b;
	}
}
void pyt1(){
	int ile=0;
	for(int i=0;i<1000;i++){
		if(jednolita(P[i].a) && jednolita(P[i].b) 
		&& anagramy(P[i].a, P[i].b)) ile++;
	}
	cout<<"jest "<<ile<<" takich wierszy\n"; 

}
void pyt2(){
	int ile=0;
	for(int i=0;i<1000;i++) if(anagramy(P[i].a, P[i].b)) ile++;
	cout<<ile<<" jest takich wierszy\n";
}
void pyt3(){
	vector <string>  w;
	for(int i=0;i<1000;i++){
		vector <char> va,vb;
		string a,b;
		for(int j=0;j<P[i].a.length();j++) va.push_back(P[i].a[j]);
                for(int j=0;j<P[i].b.length();j++) vb.push_back(P[i].b[j]);
		sort(va.begin(), va.end());
		sort(vb.begin(), vb.end());
                for(int j=0;j<va.size();j++) a += va[j];
                for(int j=0;j<vb.size();j++) b += vb[j];
		w.push_back(a);
		w.push_back(b);
	}
	sort(w.begin(), w.end());
	int k=1;
	int kmax=0;
	for(int i=1;i<1000*2;i++){
		if(w[i] == w[i-1]) k++;
		else{
			if(kmax < k) kmax = k;
			k=1;
		}
	}
	if(k > kmax) kmax = k;
	cout<<"K: "<<kmax<<endl;
}
int main(){
	wczytanie();
//	pyt1();
//	pyt2();
//	pyt3();
}
