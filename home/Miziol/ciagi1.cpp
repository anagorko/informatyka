#include<iostream>
using namespace std;

int main()
{
	int ile = 0, n, max = 0, r = 0;
	int t[1000];
	bool art = true;

	for (int i = 0; i < 100; i++ )
	{
//cout << "Ciąg" << i + 1 << endl;
		cin >> n;
//cout << n << endl;

		r = 0;

		art = true;

		for (int j = 0; j < n; j++)
		{
			cin >> t[j];
//cout << t[j] << " " << j << " " << n << endl;

			if ( j == 1 ) r = t[j] - t[j-1];
			if ( j > 0 && t[j] - t[j-1] != r ) art = false;
		}

		if ( art ) ile++;
		if ( art &&r > max ) max = r;
	}

	cout << ile << " " << max << endl;
}