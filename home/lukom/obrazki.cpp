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
	bool naprawialny(int &a, int &b);
	bool nienaprawialny() const;
	int liczba_bledow() const;
	int sum_rz(int n) const;
	int sum_ko(int n) const;

}O[200];
int obrazek::liczba_bledow() const {
	int w=0;
	for(int i=0;i<20;i++){
		if((sum_rz(i)%2) != (int)s[i][20] - '0') w++;
                if((sum_ko(i)%2) != (int)s[20][i] - '0') w++;
	}
	return w;
}
int obrazek::sum_rz(int n) const {
	int w=0;
	for(int i = 0; i< 20;i++) if(s[n][i] == '1') w++;
	return w;
}
int obrazek::sum_ko(int n) const {
	int w = 0;
	for(int i=0;i<20;i++) if(s[i][n] == '1') w++;
	return w;

}
bool obrazek::naprawialny(int &a, int &b){
	if(poprawny()) return false;
	int bledy_pio = 0;
	int bledy_poz = 0;
	for(int i=0;i<20;i++){
		if((sum_rz(i)%2) != (int)s[i][20] - '0'){ bledy_poz++; a  = i+1; }
		if((sum_ko(i)%2) != (int)s[20][i] - '0'){ bledy_pio++; b = i+1 ;}
	}
	if(bledy_pio == 1 && bledy_poz == 1) return true;
	else return false;
}
bool obrazek::poprawny() const {
	for(int i=0;i<20;i++){
		if((sum_rz(i)%2) != (int)s[i][20] - '0') return false;
		if((sum_ko(i)%2) != (int)s[20][i] - '0') return false;
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
	for(int i=0;i<200;i++){
		int a=-1, b=-1;
		if(O[i].naprawialny(a,b)){
			cout<<"naprawialny"<<i+1<<" : "<<a<<" "<<b<<endl;
		}
	}
}
int main(){
	wczytanie();
//	pyt1();
//	pyt2();
//	pyt3();
}
