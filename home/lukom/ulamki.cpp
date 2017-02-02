#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
class para {
	public:
	long long int l;
	long long int m;
	void wypisanie() const;
	bool operator < (para Pa) const;

};
vector <para> P;
para skr(para p1){
	para pw;
	pw.l = p1.l;
	pw.m = p1.m;
	long long int l1 = p1.l;
	long long int m1 = p1.m;
 	while(true){
                if(l1==0){
                        if((pw.l%m1) == 0 && (pw.m%m1) == 0 && m1 != 1){
                                pw.l/=m1;
                                pw.m/=m1;
                                m1 = pw.m;
                                l1 = pw.l;
                        }else{
                                break;
                        }
                }
                if(l1 > m1){
                        int zm = l1;
                        l1 = m1;
                        m1 = zm;
                }
                m1 -=l1;
        }
	return pw;
}
para operator + ( para p1, para p2){
	para pw;
	pw.l = p1.l*p2.m + p2.l*p1.m;
	pw.m = p1.m * p2.m;
	pw = skr(pw);
	return pw;
}
para do_mian(para p1){
	long long int b = 2*2*3*3*5*5*7*7*13;
	long long int mn = b/p1.m;
	p1.m*=mn;
	p1.l*=mn;
	return p1;
}
bool operator == (para p1, para p2){
	if(p1.l == p2.l && p1.m == p2.m) return true;
	else return false;
}
bool para::operator<(para p3) const {
	para p1;
	para p2;
	p1.m = m;
	p1.l = l;
	p1 = skr(p1);
	p2 = skr(p3);
	double liczba1 = p1.l / p1.m;
	double liczba2 = p2.l / p2.m;
	if(liczba1 < liczba2) return true;
	else if(liczba1 == liczba2) {
		if(l < p3.l) return true;
		else return false;
	}
	return false;
}
void wczytanie(){
	fstream plik;
	plik.open("../../zbior_zadan/65/dane_ulamki.txt");
	for(int i=0;i<1000;i++){
		para Pa;
		plik >> Pa.l;
		plik >> Pa.m;
		P.push_back(Pa);
	}
}
void para::wypisanie() const{
	cout<<l<<" "<<m<<endl;
}
void pkt1(){
	sort(P.begin(), P.end());
	P[0].wypisanie();
}
void pkt2(){
	int ile = 0;
	for(int i=0;i<1000;i++){
		para p1 = skr(P[i]);
		if(P[i] == p1) ile++;
	}
	cout<<"bylo zapisanych w postaci nieskracalnej: "<<ile<<endl;
}
void pkt3(){
	int w=0;
	for(int i=0;i<1000;i++){
		para p1 = skr(P[i]);
		 w += p1.l;
	}
	cout<<"suma: "<<w<<endl;
}

void pkt4(){
	long long int w;
	for(int i=0;i<1000;i++){
		para p1 = do_mian(P[i]);
		w+=p1.l;
	}
	cout<<"suma : "<<w<<endl;
}
int main(){
	wczytanie();
//	pkt1();
//	pkt2();
//	pkt3();
//	pkt4();
}
