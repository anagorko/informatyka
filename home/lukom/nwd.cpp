#include<iostream>
using namespace std;
int main(){
	int n,a;
	cin>>n;
	cin>>a;
	for(int i=1;i<n;i++){
		int b;
		cin>>b;
		while(b!=0){
			a=a%b;
			if(b>a){
				int c = a;
				a = b;
				b = c;
			}
		}
	}
	cout<<a<<"\n";
}
