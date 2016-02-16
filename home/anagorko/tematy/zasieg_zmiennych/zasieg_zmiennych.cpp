#include <iostream>

int a, b = 777;

void f(int a)
{
    a = 7;
}

void g(int b)
{
    a = b;
    
    {
        int a = 3;
        b = a;
    }
    
    a = b;
}

void h(int a, int b)
{
    a = b;
}

void i(int &a, int b)
{
    a = b;
}


int main(int argc, char **argv)
{
    {
        int a;
    
        a = 17;
    }
    
    a = 15;
    
    {
        int a;
        
        a = 13;
    }
    
    f(a);
    g(4);
    h(23, 25);
    i(b, a);
    
    std::cout << a;
    
    return 0;
}
