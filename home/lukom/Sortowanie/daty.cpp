/*
Aby posortowac wg dnia nalezy pozostawic tylko odkomentowany DZIEN.
Analogicznie reszta
*/

#define DZIEN
//#define MIESIAC
//#define ROK




#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class date {
public:
	string d;
	string m;
	string r;
	bool operator < (date& dat) const;

};
bool date::operator < (date& dat) const {

#ifdef DZIEN
	if(d < dat.d) return true;
#endif

#ifdef MIESIAC
        if(m < dat.m) return true; 
#endif

#ifdef ROK
        if(r < dat.r) return true; 
#endif
	return false;


}
int main(){
	vector <date> V;
	string d,m,r;
	while(cin>>d && cin>>m && cin>>r){
		date dat;
		dat.d = d;
		dat.m = m;
		dat.r = r;
		V.push_back(dat);
	}
	sort(V.begin(), V.end());
	
	for(int i=0;i<V.size();i++){
		cout<<V[i].d<<" "<<V[i].m<<" "<<V[i].r<<"\n";
	}
}
