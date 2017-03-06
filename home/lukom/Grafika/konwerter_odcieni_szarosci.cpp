#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

char *t;

class  picture{
	public:
	char head[2];
	char size[4];
	char bitmap_offset[4];
}P;
vector <unsigned char> O;


void wczytanie(){
	ifstream plik("/home/ki/Downloads/Tulips.bmp", ios::binary);
	char c;
	for(int i=0;i<2;i++) plik.get(P.head[i]);
	for(int i=0;i<4;i++) plik.get(P.size[i]);
	for(int i=0;i<4;i++) plik.get();
	for(int i=0;i<4;i++) plik.get(P.bitmap_offset[i]);
	for(int i=0;i<4;i++) plik.get();
	//int r = *((int*)P.size);
	t = new char[ *((int*)P.size)];
	while(plik.get(c)){
		O.push_back(c);
	}
	plik.close();
}
void zapisanie(){
	ofstream plik ("tulipany.bmp", ios::binary);
	for(int i=0;i<O.size();i++) plik << O[i];
	plik.close();
}
int main(){
	wczytanie();

	int n = 100000;

	t = new char[n];

	cout<<"rozmiar plik: "<< *((int*) P.bitmap_offset)<<endl;
	zapisanie();

}
