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
	string set(string s);
	rstring(){};
    rstring(string s);
    bool operator<(const rstring&) const;
    bool operator==(const rstring&) const;

};
rstring::rstring(string s){
	set(s);	
}
string rstring::set(string s){
	w = s;
}
string rstring::get() const{
	return w;
}
bool rstring::operator<(const rstring&) const{
	
}
vector <rstring> L;

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
	ifstream slownik;
	slownik.open("~/Download/polish.txt");
	while(slownik.is_open() && !slownik.eof()){
		rstring W;
		cin>>W;
		L.push_back(W);
	}
	slownik.close();


}