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
bool rstring::operator<(const rstring& op) const{
	string ra = rev(w);
	string rb = rev(op.w);

	for(int i=0;i<ra.length() && i<rb.length();i++){
		if(ra[i]>rb[i]) return 0;
	}
	int n = ra.length()<rb.length() ? ra.length() : rb.length();
	if(ra.substr(0,n-1)==rb.substr(0,n-1)) return ra.length()<rb.length() ? 1:0;
	return 1;
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
}
ostream& operator<<(ostream& os, const rstring &n){
	os << n.get();
}


int main(){
	//Wczytywanie
	vector <rstring> L;
	cout<<"wczytywanie..."<<endl;
	ifstream slownik;
	slownik.open("polish.txt",ios::in);
	cout<<"opened\n";
	while(slownik.is_open() && !slownik.eof()){
		rstring W;
		slownik>>W;
		L.push_back(W);
	}
	if(!slownik.is_open()) cout<<"nie znalazlem pliku"<<endl;
	slownik.close();
	//wyszukiwanie
	cout<<"wyszukiwanie...\n";
//	sort(L.begin(), L.end());
	cout<<"ee"<<endl;
	for(int i=0;i<L.size();i++){
		cout<<L[i]<<endl;
	}
}