#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;
class okrag{
	public:
	double x,y,r;
	bool I_cwiartka() const;
	bool II_cwiartka() const;
	bool III_cwiartka() const;
	bool IV_cwiartka() const;
	void wypisz() const;
}O[2000];
void okrag::wypisz() const {
	cout<<x<<" "<<y<<" "<<r<<endl;
}
bool okrag::IV_cwiartka() const {
	if(x - r > 0 && y + r < 0) return true;
	else return false;
}
bool okrag::III_cwiartka() const {
	if(x + r < 0 && y + r < 0) return true;
	else return false;
}
bool okrag::II_cwiartka() const {
	if( x + r < 0 && y - r > 0 ) return true;
	else return false;
}
bool okrag::I_cwiartka() const {
	if(x - r > 0 && y - r > 0 ) return true;
	else return false;
}
bool lustrzana_para( okrag o1, okrag o2 ){
	if(o1.r != o2.r ) return false;
	if((o1.x == -o2.x && o1.y == o2.y)
	|| (o1.x == o2.x && o1.y == -o2.y)) return true;
	else return false;
}
bool prostopadla_para( okrag o1, okrag o2 ){
	if(o1.r != o2.r) return false;
	double l12x = o2.x - o1.x;
	double l12y = o2.y - o1.y;
	double c2 = l12x * l12x + l12y * l12y;
	double a2 = o1.x * o1.x + o1.y * o1.y;
	double b2 = o2.x * o2.x + o2.y * o2.y;
	if( c2 == a2 + b2) return true;
	else return false;
}
bool punkt_wspolny( okrag o1, okrag o2 ){
	double odlx = o1.x - o2.x;
	double odly = o1.y - o2.y;
	double odl = sqrt(odlx * odlx + odly * odly);
	//wewnatrz styczne
	if(odl < o1.r || odl < o2.r){
		if(odl + o1.r == o2.r || odl + o2.r == o1.r) return true;
		else return false;
	}
	//zewnatrz styczne
	if(odl <= o1.r + o2.r) return true;
	else return false;
}
int d_l[2000];
int dlugosc_lancucha(int ost, bool wolne[2000]){
	if(d_l[ost] != -1) return d_l[ost];
	wolne[ost] = false;
	int dl=0;
	for(int i=0;i<2000;i++){
		if(!wolne[i]) continue;
		if( punkt_wspolny(O[ost], O[i]) ){
			int dl_spr = dlugosc_lancucha(i, wolne);
			if(dl_spr > dl) dl= dl_spr;
		}
	}
	if(dl==0) d_l[ost] = 1;
	else d_l[ost] = dl+1;
	return d_l[ost];
}
void wczytanie(){
	fstream plik;
	plik.open("../../zbior_zadan/79/okregi.txt");
	for(int i=0;i<2000;i++){
		plik >> O[i].x;
		plik >> O[i].y;
		plik >> O[i].r;
//		cout<<O[i].x<<" "<<O[i].y<<" "<<O[i].r<<endl;
		d_l[i] = -1;
	}
}
void pyt1(){
	int cI=0, cII=0, cIII=0, cIV=0, cn=0;
	for(int i=0;i<2000;i++){
		if(O[i].I_cwiartka() && !O[i].II_cwiartka() && !O[i].III_cwiartka() && !O[i].IV_cwiartka()) cI++;
		else if(!O[i].I_cwiartka() && O[i].II_cwiartka() && !O[i].III_cwiartka() && !O[i].IV_cwiartka()) cII++;
		else if(!O[i].I_cwiartka() && !O[i].II_cwiartka() && O[i].III_cwiartka() && !O[i].IV_cwiartka()) cIII++;
		else if(!O[i].I_cwiartka() && !O[i].II_cwiartka() && !O[i].III_cwiartka() && O[i].IV_cwiartka()) cIV++;
		else cn++;
	}
	cout<<"I cwiartka: "<<cI<<endl;
	cout<<"II cwiartka: "<<cII<<endl;
	cout<<"III cwiartka: "<<cIII<<endl;
	cout<<"IV cwiartka: "<<cIV<<endl;
	cout<<"nie zawieraja sie w zadnej cwiartce calkowicie: "<<cn<<endl;
}
void pyt2(){
	int ile_par=0;
	for(int i=0;i<1999;i++){
		for(int j=i+1;j<2000;j++){
			if(lustrzana_para( O[i], O[j] )) ile_par++;
		}
	}
	cout<<ile_par<<endl;

}
void pyt3(){
	int liczba_par=0;
	for(int i=0;i<1999;i++){
		for(int j=0;j<2000;j++){
			if(prostopadla_para(O[i],O[j])) liczba_par++;
		}
	}
	cout<<liczba_par<<endl;
}
void pyt4(){
	//uzupelnienie tabelki d_l
	int max_dl=0;
	for(int i=0;i<1000;i++){
		bool wolne[2000];
		for(int j=0;j<2000;j++) wolne[j] = true;
		int dl = dlugosc_lancucha(i, wolne);
		cout<<"długość łańcucha zaczynającego się od "<<i<<"-tego okręgu ma długość "<<dl<<endl;
		if(dl > max_dl) max_dl = dl;
	}
	cout<<"\nmaksymalna dlugosc lancucha: "<<max_dl<<endl;
}
int main(){
	wczytanie();
//	pyt1();
//	pyt2();
//	pyt3();
//	pyt4();
}
