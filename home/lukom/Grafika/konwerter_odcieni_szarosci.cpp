#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

char *t;

int char_to_int(char *w, int d){//wskaźnik do liczby, ilosc bitow kodujących liczbę
	char c[4] = {0, 0, 0, 0};
	for(int i=0;i<d && i < 4;i++) c[i] = w[i];
	int wyn = *((int*)c);
	return wyn;
}

void wczytanie(){
	ifstream plik("/home/janek/Pobrane/tulipany (1).bmp", ios::binary);
	char c;
	char head[2];
	char sizec[4];
	for(int i=0;i<2;i++) plik.get(head[i]);
	for(int i=0;i<4;i++) plik.get(sizec[i]);

	int size = char_to_int(sizec, 4);

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
	int size = *((int*)(t + 2));
	ofstream plik ("tulipany.bmp", ios::binary);
	for(int i=0;i<size;i++)	plik.put(t[i]);
	plik.close();
	cout<<"\n";
}
void filtr(){
	int size = char_to_int(t + 2, 4);
	int offset = char_to_int( t + 0xA, 4 );
	int size_of_dib_header = char_to_int( t + 0xE, 4);
	int width = char_to_int( t + 0x12, 4);
	int height = char_to_int( t + 0x16, 4);
	int num_color_planes = char_to_int( t + 0x1A, 2);
	int bits_per_pixel = char_to_int( t + 0x1C, 2);
	int size_of_raw_bitmap = char_to_int( t + 0x22, 4);

	cout<<bits_per_pixel<<"-bitowy"<<endl;
	cout<<"size = "<<size<<endl;

	int zw = 0;
	for(int i=1;i<=height;i++){
		for(int j=1;j<=width;j++){
			int pix = offset + 3*j + i*3*width;
			char sre = (t[pix] + t[pix + 1] + t[pix+2])/3;
			t[pix] = sre;
			t[pix + 1] = sre;
			t[pix + 2] = sre;
		}
	}
}
int main(){
	cout<<"program dziala dla pikow .bmp 24 bitowych\n\n";
	wczytanie();
	filtr();
	zapisanie();
}
