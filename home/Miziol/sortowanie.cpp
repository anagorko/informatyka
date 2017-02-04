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


void quick_sort(int *t, int a, int b)//to żle działa
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

	int o_pos = (b -a + 1) / 2 + a;
	int o = t[o_pos];

	int p = 0, k = b;
	int s[ (b - a + 1) ];

	for ( int i = a; i < b+1; i++ )
	{
		if(i != o_pos)
		{
			if(t[i] <= o)
			{
				s[p] = t[i];
				p++;
			}

			if(t[i] > o)
			{
				s[k] = t[i];
				k--;
			}
		}
	}

	o_pos = k;

cout << "true " << a << " " << o_pos << " " << b << endl;
char znak;
cin >> znak;

	s[o_pos] = o;

	for ( int i = a; i <= b; i++ )
	{
		t[i] = s[i-a];
	}

cout << "teraz wywołam" << a << " " << o_pos - 1 << "and" << o_pos + 1 << " " << b << endl;

	quick_sort( t, a, o_pos - 1 );
	quick_sort( t, o_pos + 1, b );

	return;
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