#include<iostream>
using namespace std;
int cz(long long int _p, long long int _q,long long int _x){
	int p[20],q[20], x[20], w[20];

	for(int i=19;i>=0;i--){
			p[i] = _p%10;
			_p /= 10;
			q[i] = _q%10;
			_q /= 10;
			x[i] = _x%10;
			_x /= 10;
			w[i]=0;
	}
	cout<<"p:";
	for(int i=0;i<20;i++)cout<<p[i];
	cout<<"\n";
	cout<<"q:";
	for(int i=0;i<20;i++)cout<<q[i];
	cout<<"\n";
	cout<<"x:";
	for(int i=0;i<20;i++)cout<<x[i];
	cout<<"\n";
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		long long int p, q;
		cin>>p;
		cin>>q;
		long long int a = 0;
		long long int b = q;
		//szukanie binarne
		while(a<b){
			long long int x = (a+b)/2;

			int stat = cz(p, q, x); 
			if(stat == -1){
				a = x + 1;
				cout<<"za małe\n";
			}else if(stat == 1){
				b = x - 1;
				cout<<"za duze\n";
			}else if(stat == 0){
				a = x;
				b = x;
				cout<<"idealne\n";
			}
			cout<<":: "<<a<<" "<<b<<endl;
		}
		cout<<"a= "<<a<<endl;
		if(a*a*a + p*a != q) cout<<"NIE\n";
		else cout<<a<<endl;
	}
	return 0;
}
