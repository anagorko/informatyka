#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class liczba{
public:
	string dw;
	int dz;
	liczba(string s);
	bool parzysta();
	bool operator<(const liczba l) const;
};
liczba::liczba(string s){
	dw = s;
	dz=0;
	for(int i=0;i<dw.length();i++) dz = dz*2 + (int)dw[i] - '0'; 
}
bool liczba::parzysta(){
	if(dw.length() > 0 && dw[dw.length()-1]=='0') return 1;
	else return 0;
}
bool liczba::operator<(const liczba l) const{
	if(dw<l.dw) return 1;
	else return 0;
}
liczba operator+(const liczba a, const liczba b){
	int sum = a.dz + b.dz;
	string s;
	while(sum>0){
		s+=(char)(sum%2)+'0';
		sum /= 2;
	}
	string w;
	for(int i=s.length()-1;i>=0;i--) w+=s[i];
	liczba l(w);
	return l;
}
int main(){
	vector <liczba> V;
	string s;
	while(cin>>s){
		liczba l(s);
		V.push_back(l);
	}

	int parz = 0;
	liczba l("");
	int l9=0;
	for(int i=0;i<V.size();i++){
		if(V[i].parzysta()) parz++;
		if(V[i].dw.length()){
			l = l + V[i];
			l9++;
		}
	}
	sort(V.begin(), V.end());

	cout<<"parzystych: "<<parz<<endl;
	cout<<"największa: "<<V[V.size()-1].dw<<" ";
	cout<<V[V.size()-1].dz<<endl;
	cout<<"jest "<<l9<<" liczb 9-cyfrowych, ktorych suma daje ";
	cout<<l.dw<<endl;
}