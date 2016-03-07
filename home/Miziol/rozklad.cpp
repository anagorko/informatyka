#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	bool p[n];
	for(int i = 0;i<n;i++)
	{
		p[i]=0;
	}

	for(int i = 2; i < n; i++)
	{
		if(n%i==0) p[i]=1;
	}

	for(int i = 0; i<n;i++)
	{
		if(p[i]==1) cout<<i<< " ";
	}
	cout<< endl;

}