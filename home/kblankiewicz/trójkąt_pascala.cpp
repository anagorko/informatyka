#include<iostream>
using namespace std;

int t[30][30];

int najwieksza_w_wierszu(int y)
{
    int b = 0;
    for(int p = 0; p <= y - 1; p++)
    {
        if(t[p][y - 1] > b) b = t[p][y - 1];
    }
    return b;
}

int liczba_cyfr(int z)// z to numer wiersza
{
    int v;
    int a = 0;
    for(int i = 0; i < z; i++)
    {
        if(t[i][z - 1] / 10 == 0)
        {
            a = a + 1;
        }
        else
        {
            v = t[i][z - 1];
            while(v > 0)
            {
                v = v / 10;
                a++;
            }
        }
    }
    return a;
}

bool brak_podzielnych(int q)
{
    for(int i = 0; i < q; i++)
    {
        if(t[i][q - 1] % 5 == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{

    // i - szerokość, j - wysokość
    for(int i = 0; i < 30; i++)
    {
        for(int j = 0; j < 30; j++)
        {
            t[i][j] = 0;
        }
   }


   for(int i = 0; i < 30; i++)
   {
        t[0][i] = 1;
        t[i][i] = 1;
   }

   for(int i = 1; i < 30; i++)
   {
        for(int j = 2; j < 30; j++)
        {
            t[i][j] = t[i-1][j-1] + t[i][j-1];
        }
   }

    for(int i = 0; i < 17; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            if(j == i)
            {
                cout<<t[j][i]<<" ";
                cout<<endl;
                break;
            }
            cout<<t[j][i]<<" ";
        }
   }

    //zadanie a)
    cout<<endl<<"10: "<<najwieksza_w_wierszu(10)<<endl<<"20: "<<najwieksza_w_wierszu(20)<<endl<<"30: "<<najwieksza_w_wierszu(30)<<endl;

    //zadanie b)
    cout<<endl<<"wiersz z liczbą cyfr: "<<endl;
    for(int i = 1; i <= 30; i++)
    {
        cout<<i<<" - "<<liczba_cyfr(i)<<endl;
    }

    //zadanie c)
    cout<<endl<<"wiersze bez podzielnych przez 5 :"<<endl;
    for(int i = 1; i <= 30; i++)
    {
        if(brak_podzielnych(i))
        {
            cout<<i<<endl;
        }
    }

    //zadanie d)
    cout<<endl<<endl;
    for(int i = 0; i < 30; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            if(j == i)
            {
                if(t[j][i] % 3 == 0)
                {
                    cout<<"x";
                }
                else
                {
                    cout<<" ";
                }
                cout<<endl;
                break;
            }
            if(t[j][i] % 3 == 0)
            {
                cout<<"x";
            }
            else
            {
                cout<<" ";
            }
        }
   }
}
