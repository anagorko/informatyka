#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

class rstring
{
	string w;
public:
	string get() const;
	void set(string s);
	string rev(string s) const;
	rstring(){};
    	rstring(string s);
    	bool operator<(const rstring&) const;
    	bool operator==(const rstring&) const;

};
rstring::rstring(string s){
	set(s);	
}
void rstring::set(string s){
	w = s;
}
string rstring::get() const{
	return w;
}
string rstring::rev(string s) const{
	string r;
	for(int i=s.length()-1;i>=0;i--) r+=s[i];
	return r;

}
int licz;
bool rstring::operator<(const rstring& op) const{
	return rev(w)  < rev(op.w);
}
bool rstring::operator==(const rstring& op) const{
	if(w.length()!= op.w.length()) return 0;
	for(int i=0;i<w.length();i++){
		if(w[i]!=op.w[i]) return 0;
	}
	return 1;
}


istream& operator>>(istream& is, rstring &n);
ostream& operator<<(ostream& os, const rstring &n);

istream& operator>>(istream& is, rstring &n){
	string s;
	is>>s;
	n.set(s);
	return is;
}
ostream& operator<<(ostream& os, const rstring &n){
	os << n.get();
	return os;
}


int main(){
	licz=0;
	vector <rstring> L;
	//wczytywanie z cin
	rstring W;
	while(cin>>W){
		L.push_back(W);
	}

	//wyszukiwanie
//	cout<<"wyszukiwanie...\n";
	sort(L.begin(), L.end());
	for(int i=0;i<L.size();i++){
		cout<<L[i]<<endl;
	}
}
