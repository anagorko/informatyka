/*
Aby obliczyc wyskosc nalezy zakomentowac SZEROKOSC, a pozostawic WYSKOSC
Aby obliczyc szerokosc nalezy zakomentowac WYSKOSC,  a pozostawic SZEROKOSC
*/

//#define SZEROKOSC
#define WYSOKOSC

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class punkt {
public:
	int x;
	int y;
	bool operator < ( punkt& p ) const;
};
bool punkt::operator < ( punkt& p ) const {

#ifdef SZEROKOSC
	if(x < p.x) return true;
#endif

#ifdef WYSOKOSC
        if(y < p.y) return true;
#endif

	else return false;
}
int main(){
	vector <punkt> V;
	int x, y;
	while(cin>>x && cin>>y){
		punkt p;
		p.x = x;
		p.y = y;
		V.push_back(p);
	}
	sort(V.begin(), V.end());
	for(int i=0; i<V.size();i++){
		cout<<V[i].x<<" "<<V[i].y<<"\n";
	}
}
