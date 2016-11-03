#include <iostream>
#include <vector>
using namespace std;
class para{
public:
	string a,b;
	para(string, string);
	bool palindrom() const;
	bool bINa() const;
	bool aPLUSb() const;
	string ab() const;
};
para::para(string a1, string b1){
	a = a1;
	b = b1;
}
bool para::palindrom() const {
	if(a.length()!=b.length()) return 0;
	for(int i=0;i<a.length();i++) if(a[i]!=b[b.length()-i-1]) return 0;
	return 1;
}
bool para::bINa() const {
	for(int i=0;i + b.length()-1<a.length();i++){
		for(int j=0;j<b.length();j++){
			if(a[i+j] != b[j]) break;
			if(j==b.length()-1) return true;
		}
	}
	return false;
}
bool para::aPLUSb() const {
	if(bINa()) return false;

	for(int i=1;i<b.length();i++){
		for(int j=0;j<b.length()-i;j++){
			//lewa strona
			if(a[j] != b[i+j]) break;
			if(j == b.length()-1-i) return false;
		}
		for(int j=0;j<b.length()-i;j++){
                        //prawa strona
                        if(a[a.length() - i + j] != b[j]) break;
                        if(j == b.length()-1-i) return false;
		}
	}
	return true;
}
string para::ab() const {
	if(bINa()) return a;
	if(aPLUSb()){
		string c = a + b;
		return c;
	}
	for(int i=1;i<b.length();i++){
                for(int j=0;j<b.length()-i;j++){
                        //lewa strona
                        if(a[j] != b[i+j]) break;
                        if(j == b.length()-1-i){
				string c = b;
				for(int  q=b.length()-i-1; q< a.length();q++) c+=a[q];
				return c;
			}
                }
                for(int j=0;j<b.length()-i;j++){
                        //prawa strona
                        if(a[a.length()- i + j] != b[j]) break;
                        if(j == b.length()-1-i){
				string c = a;
                                for(int  q=b.length()-i; q< b.length();q++) c+=b[q];
                                return c;
			}
                }
        }
}

int main(){
	vector <para> V;
	string s,s1;
	while(cin>>s && cin>>s1){
		para l(s,s1);
		V.push_back(l);
	}
	int odpa = 0;
	for(int i=0;i<V.size();i++){
		if(!V[i].palindrom()) continue;
		//cout<<V[i].a<<" "<<V[i].b<<endl;
		odpa++;
	}
	cout<<"A: "<<odpa<<" slow to palindromy\n";

	int odpb = 0;
	for(int i=0;i<V.size();i++){
		if(!V[i].bINa()) continue;
		//cout<<V[i].a<<" "<<V[i].b<<endl;
		odpb++;
	}
	cout<<"B: "<<odpb<<endl;

	int odpc = 0;
	for(int i=0;i<V.size();i++){
		if(!V[i].aPLUSb()) continue;
		//cout<<V[i].a<<" "<<V[i].b<<endl;
		odpc++;
	}
	cout<<"C: "<<odpc<<endl;

	cout<<"D:"<<endl;
	for(int i=0;i<V.size();i++){
		cout<<V[i].a<<" + "<<V[i].b<<" --> "<< V[i].ab()<<endl;
	}
}
