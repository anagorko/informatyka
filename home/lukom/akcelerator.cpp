//#define DEB
#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int t[n];
	for(int i=0;i<n;i++) cin>>t[i];
	int a;
	cin>>a;
	for(int i=0;i<a;i++){
#ifdef DEB
		cout<<"dawaj pytanie:\n";
#endif
		int b;
		cin>>b;
		//binary search
		int  p1=0, k1=n-1,p2 = 0, k2 = n-1, m1=0,m2=-1;
		while( p1 < k1 || p2 < k2){

			m1 = (p1+k1)/2;
			if(t[m1]==b){
				k1 = m1;
			}else if(t[m1]<b){
				p1 = m1+1;
				p2 = p1;
			}else{
				k1 = m1-1;
				k2 = k1;
			}

			m2 = (p2+k2+1)/2;
			if(t[m2]==b){
                                p2 = m2;
                        }else if(t[m2]<b){
                                p2 = m2+1;
				p1 = p2;
                        }else{
                                k2 = m2-1;
				k1 = k2;
                        }
#ifdef DEB
			cout<<"1: "<<p1<<" "<<k1<<endl;
			cout<<"2: "<<p2<<" "<<k2<<endl;
#endif

		}
		m1 = (p1+k1)/2;
		m2 = (p2+k2+1)/2;
		if(t[m1]!=b) m1=-1;
#ifdef DEB
		cout<<"poczatek zakresu : "<<m1<<endl;
		cout<<"koniec zakresu: "<<m2<<endl;
#endif
		if(m1!=-1)cout<< m2-m1+1<<endl;
		else cout<<0<<endl;

	}
	return 0;
}

