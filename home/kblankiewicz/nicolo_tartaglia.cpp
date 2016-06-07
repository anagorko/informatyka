#include <iostream>
using namespace std;

int szukaj(long long int p,long long int q)
{
    long long int b = 0;
    long long int e = 1000000;
    long long int z = 0;
    for(int i = 0; i < 22; i++)
    {
        if(b == e) z = z + 1;
        long long int m = (b + e)/ 2;
        //cout<<endl<<"m = "<<m;
        long long int y = m*m*m + (m * p);
        //cout<<endl<<y<<endl; 
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
    long long int t, p, q;
    cin>>t;
    for(int i = 0; i < t; i++)
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
