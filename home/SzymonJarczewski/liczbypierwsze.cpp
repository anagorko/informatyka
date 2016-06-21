#include <stdio.h>
#include <iostream>
 
using namespace std;

int main(int argc, char **argv)
{
	int n;
	cin >> n;
	for(int i=2; i*i<n; i++){
		if(n%i==0){
			cout <<"złożona";
			break;
		}
		if(i*i<n & (i+1)*(i+1)>n){
			cout << "pierwsza";
		}
	}
	return 0;
}
