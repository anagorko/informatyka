#include <iostream>
#include <fstream>
using namespace std;

char t[1000000];

void read()
{
	char c;
	int i = 0;
	ifstream obraz;
	obraz.open("input.bmp", ios::binary);
	while(obraz.get(c))
	{	
		t[i] = c;
		i++;
	}
	obraz.close();
}
	
void write()
{
	ofstream obraz;
	obraz.open("output.bmp", ios::binary);
	for(int i = 0; i < 1000000; i++)
	{
		obraz << t[i];
	}
	obraz.close();
}

void czarny_filtr()
{
	int start;
	int w, h;
	start = *((int *) (t + 10));
	w = *((int *) (t + 18));
	h = *((int *) (t + 22));
	for(int j = start; j < w * h * 4 - start; j++)
	{
		int q = (t[j] + t[j + 1] + t[j + 2])/3;
		t[j] = q;
		t[j + 1] = q;
		t[j + 2] = q;
		t[j + 3] = 255;
		j = j + 3;
	}
}
	
int main()
{	
	read();
	czarny_filtr();
	write();
}



