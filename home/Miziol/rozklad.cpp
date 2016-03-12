#include<iostream>
#include<math.h>
using namespace std;

bool pierwsza[1000];

void sito()
{
	for( int i=2; i<1000;i++) pierwsza[i]=1;

	for(int i = 2; i<1000;i++)
	{
		if(pierwsza [i]==1)
		{
			for(int j = i * 2; j<1000; j = j + i)
				pierwsza[j]=0;
		}
	}
}

int main()
{
	sito();

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
		if(p[i]==1&&pierwsza[i]==1) cout<<i<< " ";
	}
	cout<< endl;

}