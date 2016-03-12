#include<iostream>
using namespace std;
int main(){
	int p,w=0,mnoznik=1;
	cin>>p;
	for(int i=4;p>0;i*=4){
		w = w + mnoznik*(p%4);
		p/=4;
		mnoznik*=10;
	}
	cout<<w<<"\n";
}
