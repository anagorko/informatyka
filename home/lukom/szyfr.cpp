#include<iostream>
#include<fstream>
#include<vector>

using namespace std;
class enigma{
public:
	vector <string> t;
	vector <string> s;
	string zaszyfrowany(int n);

};
int main(){
	enigma E;
	string x;
	fstream txt;
	fstream szyfr;
	txt.open("tj.txt",ios::in);
	szyfr.open("klucze1.txt",ios::in);
	while(txt>>x) E.t.push_back(x);
	while(szyfr>>x) E.s.push_back(x);
	

}
