#include<iostream>
#include<fstream>
#include<vector>
#include<math.h>
using namespace std;
class wielomian {
	public:
	double a[5][4];
	void wypisz();
	double w(double x) const;
	wielomian pochodna() const;
	vector <double> roots() const;
}W;
vector <double> roots() const {
	vector <double> v;
	wielomian poch = pochodna();
}
wielomian wielomian::pochodna() const {
	wielomian poch;
	for(int i=0;i<5;i++){
		for(int j=0;j<3;j++) poch.a[i][j] = a[i][j+1]*(j+1); 
		poch.a[i][3] = 0;
	}
	return poch;
}
double wielomian::w(double x) const {
	int fragment = 0;
        if(x >= 4) fragment = 4;
        else if( x >= 3) fragment = 3;
        else if( x >= 2) fragment = 2;
        else if( x >= 1) fragment = 1;
        else if( x >= 0) fragment = 0;
        return x*x*x*a[fragment][3] + x*x*a[fragment][2] + x*a[fragment][1] + a[fragment][0];

}
void wielomian::wypisz(){
	for(int i=0;i<5;i++){
		for(int j=0;j<4;j++) cout<<a[i][j]<<" x^"<<j<<" ";
		cout<<endl;
	}
}
double find_root(double p, double k, wielomian w1){
	//algorytm bisekcji
	wielomian poch = w1.pochodna();
	if(poch.w(p) * poch.w(k) > 0){
		cout<<"pochodna przecina"<<endl;
		while(true){
			double s = (p + k)/2;
			if(w1.w(s) == 0) return s;
			if(w1.w(p) == 0) return p;
			if(w1.w(k) == 0) return k;
			if(w1.w(s) * w1.w(p) < 0) k = s;
			if(w1.w(s) * w1.w(k) < 0) p = s;
			if(fabs(p-k) <= 1/100000) return (p+k)/2;
		}
	}else if(poch.w(p) * poch.w(k) < 0){
		cout<<"pochodna styczna"<<endl;
		while(true){
                        double s = (p + k)/2;
			if(poch.w(s) == 0) return s;
			if(poch.w(p) == 0) return p;
			if(poch.w(k) == 0) return k;
                        if(poch.w(s) * poch.w(k) < 0) p = s;
                        if(poch.w(s) * poch.w(p) < 0) k = s;
                        if(fabs(p-k) <= 1/100000) return (p+k)/2;
                }
	}else if(w1.pochodna().w(p) == 0) return p;
	else if(w1.pochodna().w(k) == 0) return k;
}
void wczytanie(){
	fstream plik;
	plik.open("../../zbior_zadan/71/funkcja.txt");
	for(int i=0;i<5;i++){
		for(int j=0;j<4;j++){
			 plik >> W.a[i][j];
		}
	}
}
void pyt1(){
	cout<<W.w(1.5)<<endl;
}
void pyt2(){
	double pocz = 3;
	double kon = 4.5;
	for(int i=0;i<10000;i++){
		double sr = (pocz + kon)/2;
		if(W.w((sr+pocz)/2) > W.w((sr+kon)/2)) kon = (sr+pocz)/2;
		else pocz = (sr+kon)/2;
	}
	cout<<(pocz+kon)/2<<endl;
}
void pyt3(){
	cout<<find_root(0,5,W)<<endl;
}
int main(){
	wczytanie();
//	pyt1();
//	pyt2();
//	pyt3();
	for(int i=0;i<5;i++){
		W.a[i][0] = 2;
		W.a[i][1] = -3;
		W.a[i][2] = 1;
		W.a[i][3] = 0;
	}
	cout<<find_root(0,1.3,W)<<endl;
}
