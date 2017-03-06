#include<random>
#include<iostream>
#include<unistd.h>
#include<time.h>
using namespace std;

int main()
{
    srandom(time(NULL) + getpid());
    int x = 0;
	while(x < 1000)
	{
		cout << random() << endl;
		x += 1;
	}
}
