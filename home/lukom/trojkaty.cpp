#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
vector <int> B;
class trojkat{
	public:
	int a,b,c;
	bool przystajacy;
	bool operator < (trojkat t) const;
	bool operator == (trojkat t) const;
	void order();
};
bool trojkat::operator == (trojkat t) const {
	if(a == t.a && b == t.b && c == t.c) return true;
	else return false;
}
void trojkat::order(){
	vector <int> v;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
	sort(v.begin(),v.end());
	a = v[0];
	b = v[1];
	c = v[2];
}
bool trojkat::operator < (trojkat t) const {
	if(a < t.a) return true;
	else if(a == t.a){
		if(b < t.b) return true;
		else if(b == t.b){
			if(c < t.c) return true;
			else return false;
		}else return false;
	}else return false;
}
double  obwod(int a, int b, int c){
	if((a + b <= c)
	|| (b + c <= a)
	|| (c + a <= b)) return -1;
	return a+b+c;
}
bool prostokatny(int a, int b, int c){
	if((a*a + b*b == c*c)
	|| (b*b + c*c == a*a)
	|| (c*c + a*a == c*c)) return true;
	else return false;
}
bool przystajacy(trojkat t1, trojkat t2){
	vector <int> v,v1;
	v.push_back(t1.a);
	v.push_back(t1.b);
	v.push_back(t1.c);
	v1.push_back(t2.a);
	v1.push_back(t2.b);
	v1.push_back(t2.c);
	sort(v.begin(), v.end());
	sort(v1.begin(), v1.end());
	if(v[0] == v1[0] && v[1] == v1[1] && v[2] == v1[2]) return true;
	else return false;
}
void wczytanie(){
	fstream plik;
	plik.open("../../zbior_zadan/80/dane_trojkaty.txt");
	for(int i=0;i<500;i++){
		int l;
		plik >> l;
		B.push_back(l);
	}
}
void pyt1(){
	for(int i=2;i<B.size();i++){
		if(prostokatny(B[i-2], B[i-1], B[i])) cout<<B[i-2]<<" "<<B[i-1]<<" "<<B[i]<<"\n";
	}
}
void pyt2(){
	long long int maxobw=0;
	for(int i=0;i<B.size();i++){
		for(int j=i+1;j<B.size();j++){
			for(int q=j+1;q<B.size();q++){
				if( maxobw < obwod(B[i], B[j], B[q]) ) maxobw = obwod( B[i], B[j], B[q] );
			}
		}
	}
	cout<<maxobw<<endl;
}
void pyt3(){
	int ile = 0;
        for(int i=0;i<B.size();i++){
                for(int j=i+1;j<B.size();j++){
                        for(int q=j+1;q<B.size();q++){
				ile++;
                        }
                }
        }
        cout<<ile<<endl;
}

/*
void pyt3(){
	vector <trojkat> t;
	for(int i=0;i<B.size();i++){
                for(int j=i+1;j<B.size();j++){
                        for(int q=j+1;q<B.size();q++){
				trojkat p;
				p.a = B[i];
				p.b = B[j];
				p.c = B[q];
				p.przystajacy = false;
				t.push_back(p);
				t[t.size()-1].order();
                	}
		}
        }
	cout<<"przed sort"<<endl;
	sort(t.begin(), t.end());
	int ile=0;
	int ost=1;
	cout<<"posortowalem"<<endl;
	for(int i=1;i<t.size();i++){
		if(t[i] == t[ost]) continue;
		else{
			ile++;
			ost = i;
		}
	}
	cout<<ile<<endl;
}*/
int main(){
	wczytanie();
//	pyt1();
//	pyt2();
	pyt3();
}
