#include <iostream>
#include <vector>
using namespace std;
struct slowo
{
	vector <string> w;
};
class slownik{
	vector <slowo> l;
}S;
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
	vector <char> a, b, c;
	S.l.w.push_back();
//	string ss = sygnatura(s);	cout<<ss<<endl;


}
