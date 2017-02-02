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


void selection_sort()
{
	//tu bedzie kod
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

	bubble_sort(t, n);

	for( int i = 0; i < n; i++ )
	{
		cout << t[i] << " ";
	}
	
	cout << endl;

}