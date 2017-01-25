#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
class para {
	public:
	string a,b;
	void wypisz() const;
	bool BtoAplusC() const;
	int dl_zakonczenia() const;
}N[200];
int para::dl_zakonczenia() const {
	int dl = (a.length() < b.length())? a.length() : b.length();
	for(;dl>=0;dl--){
		if(a.substr(a.length() - dl, dl) == b.substr(b.length() - dl, dl)) return dl;
	}
}
void para::wypisz() const {
	cout<<a<<" "<<b<<endl;
}
void wczytanie(){
	fstream plik;
	plik.open("../../zbior_zadan/72/napisy.txt");
	for(int i=0;i<200;i++){
		plik >> N[i].a;
		plik >> N[i].b; 
	}
}
void pyt1(){
	bool wypisalem = false;
	int ile=0;
	for(int i=0;i<200;i++){
		if(N[i].a.length() >= 3* N[i].b.length()
		|| N[i].b.length() >= 3* N[i].a.length()){
			if(!wypisalem){N[i].wypisz(); wypisalem = true;}
			ile++;
		}
	}
	cout<<"liczba takich wierszy: "<<ile<<endl;
}
void pyt2(){
	for(int i=0;i<200;i++){
		if(N[i].b.length() > N[i].a.length() && N[i].b.substr(0,N[i].a.length()) == N[i].a){
			cout<<N[i].b<<" =  "<<N[i].a<<" + "<<N[i].b.substr(N[i].a.length(), N[i].b.length() - N[i].a.length()+1)<<endl;
		}
	}
}
void pyt3(){
	int maxdl = 0;
	for(int i=0;i<200;i++) if(N[i].dl_zakonczenia() > maxdl) maxdl = N[i].dl_zakonczenia();
	cout<<"najdluzsza wspolna czesc : "<<maxdl<<endl;
	for(int i=0;i<200;i++){
		if(N[i].dl_zakonczenia() == maxdl) N[i].wypisz();
	}
}
int main(){
	wczytanie();
//	pyt1();
//	pyt2();
//	pyt3();
}
