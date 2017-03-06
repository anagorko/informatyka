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

	int r;

	int b1 = b - ( (b - a) / 2.00 );
	int a2 = b + 1 - ( (b - a) / 2.00 );

	merging_sort ( t, a, b1 );
	merging_sort ( t, a2, b );

	for ( int i = a; i < b; i++ )
	{
		if( t[a] > t[a2])
		{
			//tu ponieżej jest błąd
			
			r = t[a2];
			
			for ( int j = a2; j > a; j-- )
			{
				t[j] = t[j-1];
			}

			t[a] = r;

			a++;
			a2++;

			//tu powyżej jest błąd
		}
	}
}


void quick_sort(int *t, int a, int b)
{
	if( a >= b ) return;
	if( a + 1 == b)
	{
		if( t[a] > t[b] )
		{
			int r = t[a];
			t[a] = t[b];
			t[b] = r;
		}
		return;
	}

	int size = b-a+1;

	int s[size];

//wczytywanie

	for( int i = 0; i <= b - a; i++)
	{
		s[i] = t[a + i];
	}

//sortowanie

	int p = 0, k = b - a;

	int s2[size];

	int o_pos = (size) / 2;
	int o = s[o_pos];

	for (int i = 0; i < size; i++ )
	{
		if( i != o_pos)
		{
			if( s[i] <= o )
			{
				s2[p] = s[i];
				p++;
			}
			if( s[i] > o )
			{
				s2[k] = s[i];
				k--;
			}
		}
	}

	s2[k] = o;

	for ( int i = 0; i < size; i++ )
	{
		s[i] = s2[i];
	}

	quick_sort( s, 0, o_pos - 1);
	quick_sort( s, o_pos + 1, size - 1);

//zapisywanie

	for( int i = 0; i < size; i++)
	{
		t[a + i] = s[i];
	}
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

	//merging_sort(t, 0, n - 1);

	quick_sort( t, 0, n-1);

	for( int i = 0; i < n; i++ )
	{
		cout << t[i] << " ";
	}
	
	cout << endl;

}