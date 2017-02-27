#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

int main()
{
	int n = 200;

	ifstream in;

	in.open( "../../zbior_zadan/72/napisy.txt" );

	vector <string> napis1;
	vector <string> napis2;

	int dluzsze = 0;

	for ( int i = 0; i < n; i++ )
	{
		string s1, s2;
		
		in >> s1 >> s2;

		napis1.push_back( s1 );
		napis2.push_back( s2 );

		if( s1.size() >= s2.size() * 3 || s2.size() >= s1.size() * 3 )
			dluzsze++;
	}

	cout << "a) " << dluzsze << endl;

	cout << "b) ";
	for ( int i = 0; i < n; i++ )
	{
		//tutaj kod 72.2
	}
}