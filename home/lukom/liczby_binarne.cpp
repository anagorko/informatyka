#include<iostream>
#include<vector>
using namespace std;
class liczba {
public:
	string b;
	bool wiecej0() const;
	bool podz2() const;
	bool podz8() const;

};
bool liczba::wiecej0() const {
	int lz = 0;
	for(int i=0;i<b.length();i++) if(b[i] == '0')lz++;
	if(2 * lz > b.length()) return true;
	else return false;
}
bool liczba::podz2() const {
	if(b[b.length()-1] == '0') return true;
	else return false;
}
bool liczba::podz8() const {
	if(b.length() >=4 && b[b.length()-1]=='0' && b[b.length()-2]=='0' && b[b.length()-3]=='0') return true;
	else return false;
}
int main(){
	string s;
	vector <liczba> V;
	while(cin>>s){
		liczba l;
		l.b = s;
		V.push_back(l);
	}
	int odpa=0;
	int odpb2 = 0;
	int odpb8 = 0;
	int najw = 0;
	int najmn = 0;
	for(int i=0;i<V.size();i++){
		if(V[i].wiecej0())odpa++;
		if(V[i].podz2()) odpb2++;
		if(V[i].podz8()) odpb8++;
		if(V[i].b > V[najw].b) najw = i;
		if(V[i].b < V[najmn].b) najmn = i;
	}
	cout<<"A: "<<odpa<<endl;
	cout<<"B: podzielnych przez dwa jest "<<odpb2<<", a podzelnych przez osiem jest "<<odpb8<<endl;
	cout<<"C: najwieksza znajduje sie w wierszu "<<najw+1<<" a najmniejsza w wierszu "<<najmn+1<<endl;
}

