#include <iostream>
#include <vector>
using namespace std;
class para{
public:
	string a,b;
	para(string, string);
	bool palindrom();
};
para::para(string a1, string b1){
	a=a1;
	b=b1;
}
bool para::palindrom(){
	if(a.length()!=b.length()) return 0;
	for(int i=0;i<a.length();i++) if(a[i]!=b[i]) return 0;
	return 1;
	}
}
int main(){
	vector <para> V;
	string s,s1;
	while(cin>>s && cin>>s1){
		para l(s,s1);
		V.push_back(l);
	}


}