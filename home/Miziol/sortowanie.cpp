#include<iostream>
using namespace std;

void bubble_sort(int *t, int n)
{
	int r;

	for( int i = n; i > 0; i-- )
	{
		for ( int j = 0; j < i - 1; j++ )
		{
			if( t[j] > t[j+1] )
			{
				r = t[j];
				t[j] = t[j+1];
				t[j+1] = r;
			} 
		}
	}

	return;
}


void selection_sort(int *t, int n)
{
	int r;

	for ( int i = 0; i < n - 1; i++)
	{
		int min = i;

		for ( int j = i + 1; j < n; j++ )
		{
			if( t[j] < t[min] ) min = j;
		}

		if( min != i )
		{
			r = t[min];
			t[min] = t[i];
			t[i] = r;
		}
	}
}


void insertion_sort(int *t, int n)
{
	int r;

	for ( int i = 1; i < n; i++ )
	{
		r = t[i];

		for( int j = 0; j <= i; j++ )
		{
			if( t[j] > r )
			{
				for ( int k = i; k > j; k--)
				{
					t[k] = t[k-1];
				}

				t[j] = r;

				break;
			}
		}
	}
}


void merging_sort(int *t, int a, int b)
{
	if( a == b ) return;

	int b1 = b - ( (b - a) / 2.00 );
	int a2 = b + 1 - ( (b - a) / 2.00 );

	merging_sort ( t, a, b1 );
	merging_sort ( t, a2, b );

	//tu ponieżej jest błąd

	for ( int i = a; i < b; i++ )
	{
		if( t[a] > t[a2])
		{
			int r = t[a2];
			t[a2] = t[i];
			t[i] = r;
			a++;
		}
	}

	//tu powyżej jest błąd
}


int main()
{
	int n;
	cin >> n;
	int t[n];

	for ( int i = 0; i < n; i++ )
	{
		cin >> t[i];
	}

	//bubble_sort(t, n);

	//selection_sort(t, n);

	//insertion_sort(t, n);

	merging_sort(t, 0, n);

	for( int i = 0; i < n; i++ )
	{
		cout << t[i] << " ";
	}
	
	cout << endl;

}