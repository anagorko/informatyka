	#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string sygnatura(string s){
	int t[256];
	for(int i=0;i<256;i++) t[i]=0;
	for(int i=0;i<s.length();i++) t[(int)s[i]]++;
	string ss;
	for(int i=0;i<256;i++){
		for(int a=0;a<t[i];a++) ss += (char)i;
	}
	return ss;
}

class Anagram
{
	string w;
	string l;
public:
	string get() const;
	string getl() const;
	void set(string s);
    Anagram(string s);
    Anagram(){};
    bool operator<(const Anagram&) const;
};
Anagram::Anagram(string s){
	set(s);
}
string Anagram::get() const{
	return w;
}
string Anagram::getl() const{
	return l;
}
void Anagram::set(string s){
	w = s;
	l = sygnatura(w);
}
bool Anagram::operator<(const Anagram& a) const{
	return l < a.l;
}
istream& operator>>(istream& is, Anagram& a){
	string s;
	is >> s;
	a.set(s);
	return is;
}

int main(){
	vector <Anagram> L;	
	//wczytywanie słownika
	while(!cin.eof()){
		Anagram A;
		cin>>A;
		L.push_back(A);
	}
	sort(L.begin(), L.end());
	//Wypisanie
	cout<<L[0].get()<<": ";
	for(int i=1;i<L.size();i++){
		if(L[i-1].getl()==L[i].getl()){ cout<<L[i].get()<<", ";
		}else{ cout<<endl<<L[i].get()<<": ";}
	}
	cout<<endl;
}
