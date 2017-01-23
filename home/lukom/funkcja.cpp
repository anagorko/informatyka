#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
double Wi(double x);
class wielomian {
	public:
	double a[4];
	void wypisz();
	double w(double x) const;
}W[5];
vector <double> roots() {
	vector <double> r;
	double pocz = 2, kon=3;
	for(int i=0;i<1000;i++){
		double sr = (pocz+kon)/2;
		if(Wi(sr) > 0) pocz = sr;
		else if(Wi(sr) < 0) kon = sr;
		else if(Wi(sr) == 0){ pocz=sr; kon=sr;}
	}
	r.push_back((pocz+kon)/2);
	return r;
}
double wielomian::w(double x) const {
	return x*x*x*a[0] + x*x*a[1] + x*a[2] + a[3];
}
void wielomian::wypisz(){
	for(int i=0;i<4;i++) cout<<a[i]<<" x^"<<3-i<<" ";
	cout<<endl;
}
double Wi(double x){
	if(x >= 4) return W[4].w(x);
	else if( x >= 3) return W[3].w(x);
	else if( x >= 2) return W[2].w(x);
	else if( x >= 1) return W[1].w(x);
	else if( x >= 0) return W[0].w(x);
}
void wczytanie(){
	fstream plik;
	plik.open("../../zbior_zadan/71/funkcja.txt");
	for(int i=0;i<5;i++){
		for(int j=0;j<4;j++) plik >> W[i].a[j];
	}
	//for(int i=0;i<5;i++) W[i].wypisz();
}
void pyt1(){
	cout<<Wi(1.5)<<endl;
}
void pyt2(){
	double pocz = 3;
	double kon = 4.5;
	for(int i=0;i<10000;i++){
		double sr = (pocz + kon)/2;
		if(Wi((sr+pocz)/2) > Wi((sr+kon)/2)) kon = (sr+pocz)/2;
		else pocz = (sr+kon)/2;
	}
	cout<<(pocz+kon)/2<<endl;
}
void pyt3(){
	vector <double> v = roots();
	for(int i=0;i<v.size();i++) cout<<v[i]<<endl;
}
int main(){
	wczytanie();
//	pyt1();
//	pyt2();
	pyt3();
}
