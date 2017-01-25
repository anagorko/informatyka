#include<iostream>
#include<fstream>
#include<string>

using namespace std;

string korekta = "";

int numer_obrazka = 0;

char obrazek[20][20];

char kol[20], wer[20];

int rewersy = 0, rekurencyjne = 0, poprawna = 0, naprawialna = 0, nienaprawialna = 0, max_bit = 0;

string int_char(int it)
{
	string s = "";

	if ( it == 0 ) return "0";

	while ( it != 0 )
	{
		s = (char) (it % 10 + 48) + s;
		it = it / 10;
	}
}


int sum_kol( int n)
{
	int w = 0;

	for ( int i = 0; i < 20; i++ )
	{
		if ( obrazek[n][i] == '1' ) w++;
	}

	return w;
}

int sum_wer( int n)
{
	int w = 0;

	for ( int i = 0; i < 20; i++ )
	{
		if ( obrazek[i][n] == '1' ) w++;
	}

	return w;
}

bool rewers()
{
	int rew = 0;

	for ( int y = 0; y < 20; y++ )
	{
		for ( int x = 0; x < 20; x++ )
		{
			if ( obrazek[x][y] == '1' ) rew++;
		}
	}

	if ( rew > 200 ) return true;

	return false;
}


bool rekurencja()
{
	for ( int x = 0; x < 10; x++ )
	{
		for ( int y = 0; y < 10; y++ )
		{
			if ( obrazek[x][y] == obrazek[x+10][y]
				&& obrazek[x][y] == obrazek[x][y+10]
				&& obrazek[x][y] == obrazek[x+10][y+10] ) ;
			else return false;
		}
	}

	return true;
}

void blendy_bit()
{
	int bl = 0, bl_kol = 0, bl_wer = 0, n_bl_kol, n_bl_wer;

	for ( int i = 0; i < 20; i++ )
	{
		if ( sum_kol(i) % 2 != (int) kol[i] - 48 )
			{
				bl++;
				bl_kol++;
				n_bl_kol = i;
			}
		if ( sum_wer(i) % 2 != (int) wer[i] - 48 )
			{
				bl++;
				bl_wer++;
				n_bl_wer = i;
			}
	}

	if ( bl == 0 ) poprawna++;
	else if ( bl_wer < 2 && bl_kol < 2 )
		{
			naprawialna++;

			if ( bl_wer == 0 && bl_kol == 1 ) korekta = korekta + int_char( numer_obrazka ) + " " + int_char( n_bl_kol ) + " 20\n";
			if ( bl_wer == 1 && bl_kol == 0 ) korekta = korekta + int_char( numer_obrazka ) + " 20 " + int_char( n_bl_wer ) + "\n";
			if ( bl_wer == 1 && bl_kol == 1 ) korekta = korekta + int_char( numer_obrazka ) + " " + int_char( n_bl_kol ) + " " + int_char( n_bl_wer ) + "\n"; 
		}
	else if ( bl > 2 ) nienaprawialna++;

	if ( bl > max_bit ) max_bit = bl;
}


int main()
{
//wczytywanie
	for ( int i = 0; i < 200; i++ )
	{
		numer_obrazka++;

		for ( int j = 0; j < 20; j++)	//wczytywanie na y
		{
			for ( int k = 0; k < 20; k++ ) //wczytywanie na x
			{
				cin >> obrazek[k][j];
//cout << obrazek [k][j];
			}

			cin >> wer[j];
//cout << wer[j] << endl;
		}

		for ( int j = 0; j < 20; j++ )
		{
			cin >> kol[j];
//cout << kol[j];
		}

//cout << endl;

		if ( rewers() ) rewersy++;

		if ( rekurencja() ) rekurencyjne++;

		blendy_bit();
	}

	cout << rewersy << endl << rekurencyjne << endl << poprawna << " " << naprawialna << " " << nienaprawialna << " " << max_bit << endl;
	cout << korekta;
}