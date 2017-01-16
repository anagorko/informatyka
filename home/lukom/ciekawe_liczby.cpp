#include<sstream>
#include<iostream>
#include<fstream>
using namespace std;
bool czy_trzy_czyniki(long long int l){
	int w=0;
	int p=3;
	int ostp=1;
	while(p<=l || w>3){
		if(l%p==0){
			l/=p;
			if(p!=ostp){ostp=p; w++;}
		}else p+=2;
	}
	if(w==3) return true;
	else return false;
}
bool palindrom(long long int l){
	std::stringstream ss;
	ss << l;
	string s;
	ss >> s;
	for(int i=0;i<s.length()/2;i++){
		if(s[i] != s[s.length()-1-i]) return false;
	}
	return true;
}
long long int odwrocona(long long int l){
	long long int w=0;
	while(l!=0){
		w = w*10 + l%10;
		l/=10;
	}
	return w;
}
bool spelnia_warunki2(long long int l){
	long long int liczba = l + odwrocona(l);
	return palindrom(liczba)? true:false;
}
long long int w(long long int l){
	long long int wynik=1;
	while(l!=0){
		wynik = wynik * (l%10);
		l/=10;
	}
	return wynik;
}
long long int t[1000];
void zad_3(){
	long long int t1[1000];
	for(int i=0;i<1000;i++) t1[i] = t[i];

	int tab[10];
	int moc[1000];
	int minmoc1=100000;
	long long int maxmoc1=-100000;
	for(int i=0;i<10;i++) tab[i]=0;
	
	for(int i=0;i<1000;i++){
		moc[i]=0;
		while(t1[i]/10 != 0){
			t1[i] = w(t1[i]);
			moc[i]++;
		}
		if(moc[i]==1 && t1[i] < minmoc1) minmoc1 = t1[i];
		if(moc[i]==1 && t1[i] > maxmoc1) maxmoc1 = t1[i];
	}
	for(int i=0;i<1000;i++) tab[moc[i]]++;
	for(int i=1;i<=8;i++) cout<<i<<" jest "<<tab[i]<<endl;
	cout<<"minimalną liczbą o mocy 1 jest liczba : "<<minmoc1<<endl;
	cout<<"maksymalna liczbą o mocy 1 jest liczba : "<<maxmoc1<<endl;
}
int main(){

	fstream file;
	file.open("../../zbior_zadan/59/liczby.txt");

	for(int i=0;i<1000;i++) file>>t[i];

	file.close();
//59.1
/*
	int ile=0;
	for(int i=0;i<1000;i++)if(czy_trzy_czynniki(t[i])ile++;
	cout<<"znajdziemy: "<<ile<<endl;
*/
//59.2
/*
	int s_w_2=0;
	for(int i=0;i<1000;i++) if(spelnia_warunki2(t[i]))s_w_2++;
	cout<<s_w_2<<endl;
*/
//59.3
/*
	zad_3();
*/
}
