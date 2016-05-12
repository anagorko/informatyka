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
//		cout<<"dawaj pytanie:\n";
		int b;
		cin>>b;
		//binary search
		int  p=0, k=n-1, m1=-1,m2=-1;
		while(p!=k){
			m1 = (p+k)/2;
			if(t[m1]==b && (m1==0 || t[m1-1]!=b) ){
				p  = k;
			}else if(t[m1]<b){
				p = m1+1;
			}else{
				k = m1;
			}
			if(p == k && t[m1]!=b)m1=-1;
		}
//		cout<<"poczatek zakresu : "<<m1<<endl;
		p=0;
		k=n-1;
		while(p!=k && m1!=-1){
                        m2 = (p+k+1)/2;
                        if(t[m2]==b){
				if(m2==n-1 || t[m2+1]!=b) k = p;
				else k = m2;
                        }else if(t[m2]<b){
                                p = m2+1;
                        }else if(t[m2]>b){
                                k = m2-1;
			}
                }
//		cout<<"koniec zakresu: "<<m2<<endl;
		if(m1!=-1)cout<< m2-m1+1<<endl;
		else cout<<0<<endl;
	}
	return 0;
}

