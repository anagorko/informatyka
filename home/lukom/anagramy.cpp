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
    Anagram(string s);
    bool operator<(const Anagram&) const;
};
Anagram::Anagram(string s){
	w = s;
	l = sygnatura(w);
}
string Anagram::get() const{
	return w;
}
string Anagram::getl() const{
	return l;
}
bool Anagram::operator<(const Anagram& a) const{
	string c = sygnatura(a.get());

	if(l.length() != c.length()) return l.length()<c.length()? 1:0;

	for(int i=0;i<l.length();i++){
		if(l[i]>c[i]) return 0;
	}
	return 1;
}
vector <Anagram> L;

int main(){
	
	cout<<"podaj ilość słów do słownika:";
	int n;
	cin>>n;
	cout<<"a teraz słowa:";
	//wczytywanie słownika
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		Anagram a(s);
		L.push_back(a);
	}
	sort(L.begin(), L.end());

//		for(int i=0;i<L.size();i++) cout<<L[i].get()<<endl;

	cout<<"ANAGRAMY:\n";

	cout<<L[0].get()<<": ";
	for(int i=1;i<L.size();i++){
		if(L[i-1].getl()==L[i].getl()){ cout<<L[i].get()<<", ";
		}else{ cout<<endl<<L[i].get()<<": ";}
	}
	cout<<endl;
}
