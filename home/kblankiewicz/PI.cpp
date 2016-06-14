#include<iostream>
#include<fstream>

using namespace std;

int cztery_jeden(string dane, string wyniki, int q)
{
    int x;
    int y;
    int l = 0;
    int z = 0;

    ifstream wejscie;
    wejscie.open(dane.c_str(), ios::in);

    ofstream wyjscie;
    wyjscie.open(wyniki.c_str(), ios::trunc);


    for(int i = 0; i < q; i++)
    {
        wejscie>>x>>y;
        if((x - 200)*(x - 200) + (y - 200)*(y - 200) == 40000)
        {
            z++;
            wyjscie<<x<<" "<<y<<endl;
        }
        if((x - 200)*(x - 200) + (y - 200)*(y - 200) < 40000)
        {
            l++;
        }
    }
    wyjscie<<l;

    wejscie.close();
    wyjscie.close();

    return (l + z);
}

double cztery_dwa(int q)
{
    double PI;
    PI = 40000 * cztery_jeden("punkty.txt", "wyniki_PI.txt", q)/q;

    cout<<PI;

    return PI;
}


int main()
{
    cztery_jeden("punkty.txt", "wyniki_PI.txt", 10000);

    cztery_dwa(10000);
}
