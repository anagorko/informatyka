#include<iostream>
using namespace std;

int t[30][30];

int najwieksza_w_wierszu(int y)
{
    int b = 0;
    for(int p = 0; p <= y; p++)
    {
        if(t[y][p] > b) b = t[y][p];
    }
    return b;
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

   for(int i = 2; i < 30; i++)
   {
        for(int j = 2; j < 30; j++)
        {
            t[i][j] = t[i-1][j-1] + t[i][j-1];
        } 
   }

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j <= i; j++)
        {   
            if(j > i)
            {
                 cout<<endl;
                 break;
            }
            cout<<t[i][j]<<" ";
        } 
   }
cout<<"10: "<<najwieksza_w_wierszu(10)<<endl<<"20: "<<najwieksza_w_wierszu(20)<<endl<<"30: "<<najwieksza_w_wierszu(30)<<endl;    

}
