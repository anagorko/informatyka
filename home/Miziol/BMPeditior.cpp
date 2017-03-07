#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

ifstream in;

char trash;

char table[4];

int chars4_to_int()
{
	int r;

	for ( int i = 0; i < 4; i++ )
		in >> table[i];
	
	r = *((int *) (table));

	return r;
}

int chars2_to_int()
{
	int r;

	for ( int i = 0; i < 2; i++ )
		in >> table[i];
	
	table[2] = (char) 0x00;
	table[3] = (char) 0x00;

	r = *((int *) (table));

	return r;
}


class BMP
{
	int x, y;
	int size;
	int begin_bitmap;
	int DIB_size;
	int number_of_planes;
	int bits_pixel;
	int compresion;
	int size_bitmap;
	int print_x, print_y;
	int color_in_pallet, important_color;

public:
	void load_DATA()
	{
		in.open( "Windows-icon.bmp" );

		for ( int i = 0; i < 2; i++ ) //wczytaj bity "BM"
			in >> trash;

		size = chars4_to_int();
cout << size << endl;

		for ( int i = 0; i < 4; i++ ) //unused
			in >> trash;

		begin_bitmap = chars4_to_int(); //numer pierwszego bity bitmapy
cout << begin_bitmap << endl;

		DIB_size = chars4_to_int(); //bity kodujące dane na temat plik
cout << DIB_size << endl;

		if ( DIB_size == 40)
		{
			x = chars4_to_int();
			y = chars4_to_int();
cout << "( " << x << ", " << y << " )\n";

			number_of_planes = chars2_to_int();
cout << number_of_planes << endl;

			bits_pixel = chars2_to_int(); //bity na pixel
cout << bits_pixel << endl;
		
			compresion = chars4_to_int(); //poziom kompresji

			size_bitmap = chars4_to_int(); //rozmiar bitmapy bez dancyh doklejonych

			print_x = chars4_to_int(); //pixele na metr druku x
			print_y = chars4_to_int(); //pixele na metr druku y

			color_in_pallet = chars4_to_int(); //kolory w palecie

			important_color = chars4_to_int(); //ważne kolory (0 = wszystkie)

		}
	}


};

void grey()
{
	;
}


int main()
{
	BMP picture1;

	picture1.load_DATA();
}