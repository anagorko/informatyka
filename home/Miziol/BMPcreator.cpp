#include<iostream>

using namespace std;


class BMP
{
	unsigned char* bitmap;
	int w, h, n;

	void setBit( int position, int n )
	{
		int bajt = position / 8, pos = position % 8;

		bitmap[bajt] = bitmap[bajt] | (128 >> pos);

		if ( n == 0 )
			bitmap[bajt] = bitmap[bajt] & ~ (128 >> pos);

	}

public:

	BMP( int _w, int _h, int _n )
	{
		int ile =  ( ( _w * _h * _n ) + 7 ) / 8;
		bitmap = new unsigned char[ ile ];

		for ( int i = 0; i < ile; i++ )
			bitmap[i] = 0x00;

		w = _w;
		h = _h;
		n = _n;
	}

	void wypisz()
	{
		int ile = ( ( w * h * n ) + 7 ) / 8;

		for ( int i = 0; i < ile; i++ )
			cout << (int) bitmap[i] << endl;
	}

	void putPixel( int x, int y, int value )
	{
		for ( int i = 0; i < n; i ++ )
		{
			setBit( ( ( ( y * w ) + x ) * n) + i , value % 2 );

			value = value / 2;
		}
	}

};

int main()
{
	BMP x( 4, 4, 4 );

	x.putPixel( 2, 1, 3 );

	x.wypisz();
}