#include <iostream>

int main(int argc, char **argv)
{
    int x = 27;
    
    while (x != 1) {
        if (x % 2 == 0) {
            x = x / 2;
        } else {
            x = 3 * x + 1;
        }
    }
    
    return 0;
}
