#include<iostream>
#include<fstream>
using namespace std;
class obrazek {
	public:
	string s[21];
	int ile_czarnych() const;
	bool rewers() const;
	bool rekurencyjny() const;
	void wypisz();
	bool poprawny() const;
	void blad(int &rzad, int &kolu) const;

}O[200];
void obrazek::blad(int &rzad, int&kolu) const {
	rzad =0; kolu =0;
	for(int i=0;i<20;i++){
                int kol=0;
                int rze=0;
                for(int j=0;j<20;j++){
                        if(s[i][j] == '1') rze++;
                        if(s[j][i] == '1') kol++;
                }
		if((int)s[i][20] - '0' != (rze%2)) rzad++;
                if((int)s[20][i] - '0' != (kol%2)) kolu++;
	}
}
bool obrazek::poprawny() const {
	for(int i=0;i<20;i++){
		int kol=0;
		int rze=0;
		for(int j=0;j<20;j++)
			if(s[i][j] == '1') rze++;
			if(s[j][i] == '1') kol++;
		}
		if((int)s[i][20] - '0' != (rze%2)) return false;
		if((int)s[20][i] - '0' != (kol%2)) return false;
	}
	return true;
}
bool obrazek::rekurencyjny() const {
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			if(s[i][j] != s[i+10][j+10] || s[i][j] != s[i][j+10] || s[i][j] != s[i+10][j]) return false;
		}
	}
	return true;
}
bool obrazek::rewers() const {
	if(ile_czarnych() > 10*20) return true;
	else return false;
}
int obrazek::ile_czarnych() const {
	int w=0;
	for(int i=0;i<20;i++){
		for(int j=0;j<20;j++){
			if(s[i][j]=='1') w++;
		}
	}
	return w;
}
void wczytanie(){
	fstream plik;
	plik.open("../../zbior_zadan/64/dane_obrazki.txt");
	for(int i=0;i<200;i++){
		for(int j=0;j<21;j++){
			plik >> O[i].s[j];
		}
	}
	plik.close();
}
void obrazek::wypisz(){
	for(int j=0;j<21;j++)
		cout<<s[j]<<"\n";
	cout<<"\n";
}
void pyt1(){
	int ile = 0;
	int najw = 0;
	for(int i=0;i<200;i++){
		if(O[i].rewers()){
			ile++;
			if(O[i].ile_czarnych() > najw) najw = O[i].ile_czarnych();
		}
	}
	cout<<ile<<" obrazkow jest rewersami\n";
	cout<<"najwiecej czarnych na jednym obrazku to: "<<najw<<endl;
}
void pyt2(){
	int ile=0;
	for(int i=0;i<200;i++){
		if(O[i].rekurencyjny()){
			ile++;
			if(ile==1) O[i].wypisz();
		}
	}
	cout<<"obrazow rekurencyjnych jest: "<<ile<<endl;
}
void pyt3(){

}
int main(){
	wczytanie();
//	pyt1();
//	pyt2();
	pyt3();
}
