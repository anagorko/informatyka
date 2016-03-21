#include <iostream>
using namespace std;

int main()
{
int liczba;
int x;
cin>>liczba;
for(int i=2;i*i<=liczba;i++)
{
	if(liczba%i==0)
	{
		cout<<"zlozona\n";
		return 0;
	}
}
cout<<"pierwsza\n";
}
