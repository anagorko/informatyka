#include <stdio.h>
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	int n;
	cin >> n;
	for(int i=2; i<=n; i++){
		if(n%i==0){
			for(int j=2; j<=i; j++){		//szuka dzielników j dzielnika i
				if(i==j){
					cout << i << endl;
				}
				if(i%j==0){		//jeżeli j jest dzielnikiem
					break;
				}
			}
		}
	}
	return 0;
}
