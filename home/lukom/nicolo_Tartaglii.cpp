#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		long long int p, q, x;
		cin>>p;
		cin>>q;
		long long int a = 0;
		long long int b = q;
		//algorytm
		while(a!=b){
			x = (a+b)/2;
			if(x*x*x + p*x < q){
				a = x + 1;
			}else if(x*x*x + p*x > q){
				b = x - 1;
			}
		}
		if(a*a*a + p*a != q) cout<<"NIE\n";
		else cout<<a<<endl;
	}
	return 0;
}
