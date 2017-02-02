#include<random>
#include<iostream>
#include<unistd.h>
#include<time.h>
using namespace std;

int main()
{
    srandom(time(NULL) + getpid());
    
    cout << random() << " " << random() << endl;
}
