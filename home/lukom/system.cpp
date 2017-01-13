#include<iostream>
using namespace std;
string cyfra = "0123456789ABCDEF";
int z_ciagu_cyfr(char a){
	for(int i=0;i<cyfra.length();i++){
		if(a == cyfra[i]){
			return i;
		}
	}
	return -100000;
}
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
	if(l[0]=='-'){
		minus = true;
		i=1;
	}
	for(;i<l.length();i++){
		n = n*b + z_ciagu_cyfr(l[i]);
	}
	return minus? -n : n;
}
int main(){
	int n;
	int b;
	cin>>n;
	cin>>b;
	cout<<z_systemu(na_system(n,b), b)<<endl;
return 0;
}
