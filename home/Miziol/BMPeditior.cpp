#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

ifstream in;

ofstream out;

char trash;

char table[4];

//int obraz[256][256][4];

int *obraz;

int chars4_to_int()
{
	int r;

	for ( int i = 0; i < 4; i++ )
		in.get( table[i] );
	
	r = *((int *) (table));

	return r;
}

int chars2_to_int()
{
	int r;

	for ( int i = 0; i < 2; i++ )
		in.get( table[i] );
	
	table[2] = (char) 0x00;
	table[3] = (char) 0x00;

	r = *((int *) (table));

	return r;
}


int char_to_int()
{
	int r;

	in.get( table[0] );
	
	table[1] = (char) 0x00;
	table[2] = (char) 0x00;
	table[3] = (char) 0x00;

	r = *((int *) (table));

	return r;
}


void int_to_chars4(int x)
{
	char a = (char)(x & 0xff);
	char b = (char)((x >> 8) & 0xff);
	char c = (char)((x >> 16) & 0xff);
	char d = (char)((x >> 24) & 0xff);
	
	out << a << b << c << d;
}


void int_to_chars2(int x)
{
	char a = (char) (x & 0xff);
	char b = (char)((x >> 8) & 0xff);
	
	out << a << b;
}


void int_to_char(int x)
{
	char a = (char)(x & 0xff);
	
	out << a;
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
			in.get( trash );

		size = chars4_to_int();
//cout << size << endl;

		for ( int i = 0; i < 4; i++ ) //unused
			in.get( trash );

		begin_bitmap = chars4_to_int(); //numer pierwszego bity bitmapy
//cout << begin_bitmap << endl;

		DIB_size = chars4_to_int(); //bity kodujące dane na temat plik
//cout << DIB_size << endl;

		if ( DIB_size == 40)
		{
			x = chars4_to_int();
			y = chars4_to_int();
//cout << "( " << x << ", " << y << " )\n";

			number_of_planes = chars2_to_int();
			bits_pixel = chars2_to_int(); //bity na pixel
//cout << number_of_planes << endl;
//cout << bits_pixel << endl;
		
			compresion = chars4_to_int(); //poziom kompresji
//cout << compresion << endl;

			size_bitmap = chars4_to_int(); //rozmiar bitmapy bez dancyh doklejonych
//cout << size_bitmap << endl;

			print_x = chars4_to_int(); //pixele na metr druku x
			print_y = chars4_to_int(); //pixele na metr druku y
//cout << print_x << " " << print_y << endl;

			color_in_pallet = chars4_to_int(); //kolory w palecie
//cout << color_in_pallet << endl;

			important_color = chars4_to_int(); //ważne kolory (0 = wszystkie)
//cout << important_color << endl;
		}

		int dane_tablicy[x][y][bits_pixel];

		obraz = &dane_tablicy[0][0][0];

		if ( bits_pixel == 32 )
			for ( int i = 0; i < x; i++ )
				for ( int j = 0; j < y; j++ )
					for ( int k = 0; k < 4; k++)
					{
						obraz[i][j][k] = char_to_int();
					}

		in.close();
	}

	void export_DATA()
	{
		out.open( "Windows-icon2.bmp", ios::binary );

		out << "BM"; //wypisz bity "BM"

		int_to_chars4( size );	

//cout << " size" << size << endl;

		char unused = (char) 0x00;
		out << unused << unused << unused << unused;

		int_to_chars4( begin_bitmap );//numer pierwszego bity bitmapy

		int_to_chars4( DIB_size );//bity kodujące dane na temat plik

		if ( DIB_size == 40)
		{
			int_to_chars4( x );
			int_to_chars4( y );

			int_to_chars2( number_of_planes );
			int_to_chars2( bits_pixel );//bity na pixel
//cout << "asd" << bits_pixel << endl;

			int_to_chars4( compresion ); //poziom kompresji

			int_to_chars4( size_bitmap );//rozmiar bitmapy bez dancyh doklejonych

			int_to_chars4( print_x );//pixel na metr druku x
			int_to_chars4( print_y );

			int_to_chars4( color_in_pallet ); //kolory w palecie

			int_to_chars4( important_color ); //ważne kolory (0 = wszystkie)
		}

		if ( bits_pixel == 32 )
			for ( int i = 0; i < x; i++ )
				for ( int j = 0; j < y; j++ )
					for ( int k = 0; k < 4; k++)
						int_to_char( obraz[i][j][k] );

		in.close();
	}

	void grey()
	{
		for ( int i = 0; i < x; i++ )
			for ( int j = 0; j < y; j++ )
			{
				int sum = obraz[i][j][0] + obraz[i][j][1] + obraz[i][j][2];

				obraz[i][j][0] = sum/3; //B
				obraz[i][j][1] = sum/3; //G
				obraz[i][j][2] = sum/3; //R
			}
	}

	void negative()
	{
		for ( int i = 0; i < x; i++ )
			for ( int j = 0; j < y; j++ )
			{
				obraz[i][j][0] = 255 - obraz[i][j][0]; //B
				obraz[i][j][1] = 255 - obraz[i][j][1]; //G
				obraz[i][j][2] = 255 - obraz[i][j][2]; //R
			}
	}

	void sepia()
	{
		for ( int i = 0; i < x; i++ )
			for ( int j = 0; j < y; j++ )
			{
				int sum = obraz[i][j][0] + obraz[i][j][1] + obraz[i][j][2];

				obraz[i][j][0] = sum/3*0.85; //B
				obraz[i][j][1] = sum/3; //G
				obraz[i][j][2] = (int) ( sum/3*1.15 ); //R

				if( obraz[i][j][2] > 255 )
					obraz[i][j][2] = 255;
			}
	}

	void blue()
	{
		for ( int i = 0; i < x; i++ )
			for ( int j = 0; j < y; j++ )
			{
				int sum = obraz[i][j][0] + obraz[i][j][1] + obraz[i][j][2];

				obraz[i][j][0] = sum/3*1.1; //R
				obraz[i][j][1] = sum/3; //G
				obraz[i][j][2] = sum/3; //R

				if( obraz[i][j][0] > 255 )
					obraz[i][j][2] = 255;
			}
	}
};




int main()
{
	BMP picture1;

	picture1.load_DATA();

	//picture1.grey();

	//picture1.negative();

	//picture1.sepia();

	picture1.blue();

	picture1.export_DATA();
}