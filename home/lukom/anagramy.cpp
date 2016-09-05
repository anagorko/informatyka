#include <iostream>
#include <vector>
using namespace std;
class slownik{
public:
	vector <string> w;
}L;
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

int main(){
	
	cout<<"podaj ilość słów do słownika:";
	int n;
	cin>>n;
	cout<<"a teraz słowa:";
	//wczytywanie słownika
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		L.w.push_back(s);
	}
	cout<<"ANAGRAMY:\n";
	
	//szukanie anagramu:
	for(int i=0;i<L.w.size();i++){
		cout<<L.w[i]<<": ";
		for(int a=0;a<L.w.size();a++){
			if(a==i)continue;
			if(sygnatura(L.w[i])==sygnatura(L.w[a]) )cout<<L.w[a]<<", ";
		}
		cout<<"\n";
	}
}
