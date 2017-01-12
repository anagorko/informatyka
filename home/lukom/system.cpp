#include<iostream>
using namespace std;
string cyfra = "0123456789ABCDEF";
string na_system(int n, int b){
	string s = "";
	bool minus = 0;
	if(n<0){
		n*=-1;
		minus = true;
	}
	while(n>0){
		s = cyfra[n%b] + s;
		n/=b;
	}
	if(minus) s = "-" + s;
	return s;
}
int z_systemu(string l, int b){
	int n=0;
	bool minus = 0;
	int i=0;
	if(l[0]="-"){
		minus = true;
		i=1;
	}
	for(;i<l.length();i++){
		n = n*b + (int)l[i];//do poprawy
	}
	return minus? -n : n;
}
int main(){
	int n;
	int b;
	cin>>n;
	cin>>b;
	cout<<na_system(n,b)<<endl;
return 0;
}
