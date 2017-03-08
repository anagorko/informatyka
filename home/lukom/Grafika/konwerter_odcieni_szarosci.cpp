#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

int size;
char *t;


void wczytanie(){
	ifstream plik("/home/janek/Pobrane/tulipany (1).bmp", ios::binary);
	char c;
	char head[2];
	char sizec[4];
	for(int i=0;i<2;i++) plik.get(head[i]);
	for(int i=0;i<4;i++) plik.get(sizec[i]);

	size = *((int*)sizec);

	t = new char[size];

	for(int i=0;i<2;i++) *(t + i) = head[i];
	for(int i=0;i<4;i++) *(t + 2 + i) = sizec[i];

	int k = 6;
	while(plik.get(c)){
		*(t + k) = c;
		k++;
	}
	plik.close();
}
void zapisanie(){
	ofstream plik ("tulipany.bmp", ios::binary);
	for(int i=0;i<size;i++)	plik.put(t[i]);
	plik.close();
}
void filtr(){
	int offset = *((int*)(t + 2 * 3 + 4 ));
	int size_of_dib_header = *((int*)(t + 14));
	int width = *((int*)(t + 18));
	int height = *((int*)(t + 22));
	int num_color_planes = *((int*)(t + 26));
	int bits_per_pixel = *((int*)(t + 28));
	int size_of_raw_bitmap = *((int*)(t + 0x22));
	cout<<bits_per_pixel<<"-bitowy"<<endl;
	cout<<"size = "<<size<<endl;
	cout<<800*600*3<<endl;
	cout<<(int)t[offset]<<endl;
	int zw = 0;
	for(int i=1;i<=height;i++){
		for(int j=1;j<=width;j++){
			int pix = offset + 3*j + i*3*width;
			int sre = (t[pix] + t[pix + 1] + t[pix+2])/3;
			t[pix] = sre;
			t[pix + 1] = sre;
			t[pix + 2] = sre;
		}
	}
}
int main(){
	cout<<"poram dziala dla pikow .bmp 24 bitowych\n";
	wczytanie();
	filtr();
	zapisanie();
}
