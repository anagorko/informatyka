#include<iostream>
#include<math.h>


using namespace std;

#define temp_zero -300 //punkt zero dla temperatury (wartość w dC)
#define pres_zero 600 //punkt zero dla ciśnienia (wartość w hPa)
#define ilosc_bajtow  255 //ilość bajtów do zapisu

//kod zapisuje w 44 bity kod serii, kod pomiaru, temperature i ciśnienie
//oraz tyle pomairów ile jest możliwe ze spektrometru

unsigned char data[ilosc_bajtow];


void kompresja( int *seria, int *pomiar, int *temp, int *pres, int spekt[] )
{
	if ( *seria >= 256 )
		*seria = *seria % 256;
	while ( *seria  < 0 )
		*seria = *seria + 256;

	if ( *pomiar >= 65536 )
		*pomiar = *pomiar % 65536;
	while ( *pomiar  < 0 )
		*pomiar = *pomiar + 65536;

	int t = *temp - temp_zero;
	int p = *pres - pres_zero;

	if ( t >= 1024 )
		t = t % 1024;
	while ( t  < 0 )
		t = t + 1024;

	if ( p >= 1024 )
		p = p % 1024;
	while ( p  < 0 )
		p = p + 1024;

	for ( int i = 0; i < 256; i++ )
	{
		if ( spekt[i] >= 1024 )
			spekt[i] = 1023;
		while ( spekt[i]  < 0 )
			spekt[i] = spekt[i] + 1024;
	}

	data[0] = (char) *seria;
	data[1] = (char) ( *pomiar / 256 );
	data[2] = (char) ( *pomiar % 256 );

	data[3] = (char) ( t / 4 );

	p = p + ( (t % 4) * 1024 );

	data[4] = (char) ( p / 16 );

	int spektrometr = 0, robocza = (p % 16) * 1024 + spekt[spektrometr], reszta = 6;

	data[5] = (char) ( robocza / 64 );

	robocza = robocza % 64;

	spektrometr++;

	for ( int i = 6; i < ilosc_bajtow; i++ )
	{
		if ( spektrometr >= 256 )
			break;

		robocza = robocza * 1024 + spekt[spektrometr];

		reszta = reszta + 10 - 8;

		data[i] = (char) ( robocza / pow( 2, reszta ) );

//cout << "r" << robocza << "." << pow( 2, reszta ) << "=" << (int) data[i] << " ";

		robocza = robocza % (int) pow( 2, reszta );

		if ( reszta == 8 )
		{
			i++; 

			data[i] = (char) robocza;

			robocza = 0;

			reszta = 0;
		}

		spektrometr += 2;
	}

	//tutaj trzeba posłać to od radia

/*cout << spekt[1] << endl <<"\n\n\n po konwersji\n";

for ( int i = 0; i < 255; i++ )
{
	cout << (int) data[i] << " ";
}*/

}


void dekompresja( int *seria, int *pomiar, int *temp, int *pres, int spekt[] )
{
	*seria = (int) data[0];
	*pomiar = ( (int) data[1] ) * 256 + (int) data[2];

	*temp = (int) data[3] * 4 + ( (int) data[4] / 64 );
	*pres = ( (int) data[4] % 64 * 16 ) + ( (int) data[5] / 16 );

	*temp = *temp + temp_zero;
	*pres = *pres + pres_zero;

	int spektrometr = 0, robocza = ( (int) data[5] % 16), reszta = 4;

//cout << (int) data[5] << " test " << robocza << endl;

	for ( int i = 6; i < ilosc_bajtow; i++ )
	{
		if ( spektrometr >= 256 )
			break;

		robocza = robocza * 256 + (int) data[i];	

//cout << (int) data[i] << " test " << robocza << endl;

		reszta = reszta + 8 - 10;

		if ( reszta < 0 )
		{
			i++; 

			robocza = robocza * 256 + (int) data[i];

			reszta = reszta + 8;
		}

		spekt[spektrometr] = robocza / (int) pow( 2, reszta );
		spekt[spektrometr + 1] = robocza / (int) pow( 2, reszta );

		robocza = robocza % (int) pow( 2, reszta );

		spektrometr += 2;
	}
}



int main()
{
	int s = 45, p = 9509, t = 396, c = 1023;
	int tablica[255];

	for ( int i = 0; i < 255; i++ )
	{
		tablica[i] = 0;
	}

tablica[0] = 78;
tablica[1] = 111;
tablica[2] = 69;

cout << "przed kompresją" << endl;
cout << s << " " << p << endl << t << endl << c << endl;
cout << tablica[0] << " " << tablica[1] << " " << tablica[2] << endl; 

	kompresja( &s, &p, &t, &c, &tablica[0] );

tablica[0] = 0;
tablica[1] = 0;
tablica[2] = 0;

cout << endl << "po" << endl;

	dekompresja( &s, &p, &t, &c, &tablica[0] );

cout << s << " " << p << endl << t << endl << c << endl;
cout << tablica[0] << " " << tablica[1] << " " << tablica[2] << " " << tablica[3] << " " << tablica[4] << " " << tablica[5] << endl;
}
