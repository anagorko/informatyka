#include <iostream>
using namespace std;

int t[20][12];
int u[20][12];

void pokolenie()
{
	for(int i = 0; i < 20; i++)
	{
		for(int j = 0; j < 12; j++)
		{
			if(t[i][j] == 0)
			{
				if(t[(i+19)%20][(j+11)%12]+t[(i+19)%20][j]+t[(i+19)%20][j+1]+t[i][(j+11)%12]+t[i][j+1]+t[i+1][(j+11)%12]+t[i+1][j]+t[i+1][j+1] == 3)
				{
					u[i][j] = 1;
				}
				else
				{
					u[i][j] = 0;
				}
			}
			else
			{
				if(t[i-1][j-1]+t[i-1][j]+t[i-1][j+1]+t[i][j-1]+t[i][j+1]+t[i+1][j-1]+t[i+1][j]+t[i+1][j+1] == 3 || t[i-1][j-1]+t[i-1][j]+t[i-1][j+1]+t[i][j-1]+t[i][j+1]+t[i+1][j-1]+t[i+1][j]+t[i+1][j+1] == 2)
				{
					
				}
			}
		}
	}
}
int main()
{
	int x;
	while(cin!=eof())
	{
		cin>>x;
		for(int j = 0; j < 12; j++)
		{
			for(int i = 0; i < 20; i++)
			{
				t[i][j] =x 
			}
		}
	}
}
