#include <stdio.h>
#include <iostream>
 
using namespace std;

int main (int argc, char **argv)
{
	int s=1;
	int e=2;
	int n=0;
	for(; e<4000000;){
		if(e%2==0){
			n=n+e;
		}
		int x=s;
		s=e;
		e=e+x;
	}
	cout << n;
	return 0;
}
