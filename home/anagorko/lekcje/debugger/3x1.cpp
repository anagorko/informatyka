#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int x = 27,i=0;
    
    while (x != 1) {
        if (x % 2 == 0) {
            x = x / 2;
            i++;
        } else {
            x = 3 * x + 1;
            i++;
        }
    }
    cout<<i;
    
    return 0;
}
