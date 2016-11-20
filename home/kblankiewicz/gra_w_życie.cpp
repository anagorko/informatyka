#include <iostream>
using namespace std;

int t[20][12];
int u[20][12];
int y = 0;
int z = 1;

void pokolenie()
{
	for(int i = 0; i < 20; i++)
	{
		for(int j = 0; j < 12; j++)
		{

			if(t[i][j] == 0)
			{
				if(t[(i+19)%20][(j+11)%12]+t[(i+19)%20][j]+t[(i+19)%20][(j+1)%12]+t[i][(j+11)%12]+t[i][(j+1)%12]+t[(i+1)%20][(j+11)%12]+t[(i+1)%20][j]+t[(i+1)%20][(j+1)%12] == 3)
				{
					u[i][j] = 1;
					//cout<<"wstaje";
				}
				else
				{
					u[i][j] = 0;
				}
			}
			else
			{
				if(t[(i+19)%20][(j+11)%12]+t[(i+19)%20][j]+t[(i+19)%20][(j+1)%12]+t[i][(j+11)%12]+t[i][(j+1)%12]+t[(i+1)%20][(j+11)%12]+t[(i+1)%20][j]+t[(i+1)%20][(j+1)%12] == 3 || t[(i+19)%20][(j+11)%12]+t[(i+19)%20][j]+t[(i+19)%20][(j+1)%12]+t[i][(j+11)%12]+t[i][(j+1)%12]+t[(i+1)%20][(j+11)%12]+t[(i+1)%20][j]+t[(i+1)%20][(j+1)%12] == 2)
				{
                    u[i][j] = 1;
				}
				else
                {
                    u[i][j] = 0;
                    //cout<<"gine";
                }
			}
		}
	}
    int x = 0;
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 12; j++)
        {
            if(t[i][j] == u[i][j])
            {
                x = x + 1;
            }
        }
    }
    if(x == 240)
    {
        y = 1;
        cout<<"mam"<<z;
    }
	for(int i = 0; i < 20; i++)
	{
		for(int j = 0; j < 12; j++)
		{
            t[i][j] = u[i][j];
		}
	}

}
int main()
{


    for(int j = 0; j < 12; j++)
    {
        for(int i = 0; i < 20; i++)
        {
            //cin>>x;
            t[i][j] = 0;
        }
    }

    t[7][4] = 1;
    t[9][4] = 1;
    t[10][4] = 1;
    t[7][5] = 1;
    t[8][5] = 1;
    t[9][5] = 1;
    t[8][6] = 1;

    for(int j = 0; j < 12; j++)
    {
        for(int i = 0; i < 20; i++)
        {
            cout<<t[i][j];
        }
        cout<<endl;
    }

	for(int i = 0; i < 50; i++)
    {
        pokolenie();
        z = z + 1;
        if(y == 1)
        {
            break;
        }
    }

    cout<<endl<<endl;
    for(int j = 0; j < 12; j++)
    {
        for(int i = 0; i < 20; i++)
        {
            cout<<t[i][j];
        }
        cout<<endl;
    }
}

/*
ODPOWIEDZI:
5.1 - 4
5.2 - 7
5.3 - 51 pokolenie; jest 8 żywych komórek
*/
