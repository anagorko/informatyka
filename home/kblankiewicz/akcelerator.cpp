
#include <iostream>
using namespace std;

int ile(int p) // pytaj¹ nas o p
{
    double p1 = p - 0.5;
    double p2 = p + 0.5;
    int b = 0;
    int n;
    int t[n];
    int e = n;
    int r1; // miejsce w t[n] pierwszego wyst¹pienia p
    int r2; //miejsce w t[n] ostatniego wyst¹pienia p
    //int z = 0;
    for(int i = 0; i < 30; i++)
    {
       // if(b == e) z = z + 1;
        if(e == b + 1)
        {
            r1 = b;
            break;
        }
        int m = (b + e)/2;
        if(m > p1)
        {
            e = m;
        }
        if(m < p1)
        {
            b = m;
        }
    }
    for(int i = 0; i >= 0; i++)
    {
        if(t[r1 + 1] != p)
        {
            r2 = r1 + i;
            break;
        }
    }
    return (r2 - r1 + 1);
}

int main()
{
	int n;
	int p;
	cin>>n;
	int t[n];
	for(int i = 0; i < n; i++)
	{
		cin>>t[i];
	}
	int q;
	cin>>q;
	for(int i = 0; i < q; i++)
    {
        cin>>p;
        cout<<ile(p);
    }
}
