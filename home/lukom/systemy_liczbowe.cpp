#include<vector>
#include<fstream>
#include<iostream>
using namespace std;
class liczby{
	public:
	vector <string> s;
	void wypisz() const;
};
void liczby::wypisz() const{
	for(int i=0;i<s.size();i++){
		cout<<s[i];
	}
	cout<<endl;
}
int main(){
	liczby L[3];
	ifstream d1;
	d1.open("../../zbior_zadan/58/dane_systemy1.txt");
	string s;
	while(d1>>s){
		L[0].s.push_back(s);
	}
	L[0].wypisz();

}
