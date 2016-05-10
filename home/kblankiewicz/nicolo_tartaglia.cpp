#include <iostream>
#include <math.h>
using namespace std;

int szukaj(int p, int q)
{
    int b = 0;
    int e = 1000000;
    int z = 0;
    for(int i = 0; i < 22; i++)
    {
        if(b == e) z = z + 1;
        int m = (b + e)/ 2;
        cout<<endl<<"m = "<<m;
        long long int y = pow(m, 3) + (m * p);
        cout<<(m*p)<<"  "<<pow(m, 3)<<"  "<<y;   <<<<<=====DLA P=7 I Q=160 MÓJ KOMPUTER LICZY 125 + 35 = 159 ??????
        if(y == q)
        {
            return m;
        }
        if(y < q)
        {
            b = m + 1;
        }
        if(y > q)
        {
            e = m - 1;
        }
    }
    return 0;
}

int main()
{
    int t, p, q;
    cin>>t;
    for(int i = 0; i <= t; i++)
    {
        cin>>p;
       // cout<<"p = "<<p<<endl;
        cin>>q;
        //cout<<"q = "<<q<<endl;

        int wynik = szukaj(p, q);

        if(wynik == 0) cout<<"NIE"<<endl;
        else cout<<wynik<<endl;
    }
}
