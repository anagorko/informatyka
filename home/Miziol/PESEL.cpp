#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	vector <string> base;

	string s;

	while(cin >> s)
	{
		base.push_back(s);
	}
	
	cout << "a) ";
	
	int gru = 0;

	for ( int i = 0; i < base.size(); i++)
	{
		if ( base[i][2] == '1' && base[i][3] == '2') gru++;
	}
	
	cout << gru << endl;
	
	cout << "b) ";

	int kob = 0;

	for ( int i = 0; i < base.size(); i++)
	{
		if ( base[i][9] % 2 == 0) kob ++;
	}
	
	cout << kob << endl;

	cout << "c) ";

	sort( base.begin(), base.end() );

	int rok, tes, max = 0, ile = 1;

	tes = ( (int) base[0][0] - '0' ) * 10 + ((int) base[0][1] - '0');

	for ( int i = 1; i < base.size(); i++ )
	{
		if( tes == ( (int) base[i][0] - '0' ) * 10 + ((int) base[i][1] - '0') ) ile++;
		else
		{
			if ( ile > max )
			{
				rok = tes;
				max = ile;
			}
			tes = ( (int) base[i][0] - '0' ) * 10 + ((int) base[i][1] - '0');
			ile == 1;
			
		}
		
	}

	cout << "19" << rok << " " << ile << endl;

	cout << "d) ";

	int kon;

	for ( int i = 0; i < base.size(); i++)
	{
		kon = 0;
		kon = ((int) base[i][0] - '0')
+ (3 * ((int) base[i][1] - '0'))
+ (7 * ((int) base[i][2] - '0'))
+ (9 * ((int) base[i][3] - '0'))
+ ((int) base[i][4] - '0')
+ (3 * ((int) base[i][5] - '0'))
+ (7 * ((int) base[i][6] - '0'))
+ (9 * ((int) base[i][7] - '0'))
+ ((int) base[i][8] - '0')
+ (3 * (int) (base[i][9] - '0'));

		kon = kon % 10;
		if ( (kon == 0 && (int) base[i][10] - '0' != 0) || (kon != 0 && (int) base[i][10] - '0' != (10 - kon)) )
			cout << base[i] << endl;
	}

	cout << "e) ";

	int t[10];

	for ( int i = 0; i < 10; i++) t[i] = 0;

	for (int i = 0; i < base.size(); i++)
	{
		t[ (int) base[i][0] - '0' ] ++;
	}

	for ( int i = 0; i < 10; i++)
	{
		cout << i * 10 << " " << t[i] << endl;
	}
}
