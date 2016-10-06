#include<iostream>
#include<fstream>
#include<vector>

using namespace std;
class enigma{
public:
	vector <string> t;
	vector <string> s;
	string szyfrowanie(int n) const;
	string odszyfrowanie(int n) const;

};
string enigma::szyfrowanie(int n) const{
	string w;
	for(int i=0;i<t[n].length();i++){
		char a;
		a=(char)( (int)t[n][i] + (int)s[n][i%s[n].length()] - 'A'+1 );
		if((int)a>90) a-=26;
		w+=a;
	}
	return w;
}
string enigma::odszyfrowanie(int n) const{
	string w;
        for(int i=0;i<t[n].length();i++){
                char a;
                a=(char)( (int)t[n][i] - (int)s[n][i%s[n].length()] + 'A'-1 );
                if((int)a<65) a+=26;
                w+=a;
        }
        return w;

}
int main(){
	cout<<"Czesc"<<endl;
	//podpunkt A:
/*	enigma E;
	string x;
	fstream txt;
	fstream szyfr;
	txt.open("tj.txt",ios::in);
	szyfr.open("klucze1.txt",ios::in);
	while(txt>>x) E.t.push_back(x);
	while(szyfr>>x) E.s.push_back(x);

	for(int i=0;i<E.t.size();i++){
		cout<<"z: "<<E.t[i]<<"   kod: "<<E.s[i]<<"    "<<E.szyfrowanie(i)<<endl;
	}
*/
	//podpunkt B:
	enigma B;
	string x;
        fstream sz;
        fstream kl;
        sz.open("sz.txt",ios::in);
        kl.open("klucze2.txt",ios::in);
        while(sz>>x) B.t.push_back(x);
        while(kl>>x) B.s.push_back(x);

        for(int i=0;i<B.t.size();i++){
                cout<<"z: "<<B.t[i]<<"   kod: "<<B.s[i]<<"    "<<B.odszyfrowanie(i)<<endl;
        }


}
