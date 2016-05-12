#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int t[n];
	for (int i = 0; i < n; i++)
	{
		cin >> t[i];
	}

	int rotation, search;
	cin >> rotation;

	int start, end;

	for(int i = 0; i < rotation; i++)
	{
		cin >> search;

		start = 0;
		end = n;

		while(true)
		{
			if(start == end)
			{
				if(start != search)
				{
					start++;
					break;
				}
			}

			if( t[(start + end) / 2] == search)
			{
				int start1 = start, end1 = (start + end) / 2 - 1;
				while(start1 != end1)
				{
					if( t[(start + end) / 2] < search)
					{
						start = (start + end) / 2;
					}
					if( t[(start + end) / 2] = search)
					{
						end = (start + end) / 2;
					}
				}

				int start2 = (start + end) / 2 + 1, end2 = end;
				while(start2 != end2)
				{
					if( t[(start + end) / 2] = search)
					{
						start = (start + end) / 2;
					}
					if( t[(start + end) / 2] > search)
					{
						end = (start + end) / 2;
					}
				}
				
			}else{
				if( t[(start + end) / 2] < search)
				{
					start = (start + end) / 2;
				}
				if( t[(start + end) / 2] > search)
				{
					end = (start + end) / 2;
				}
			}
		}

		cout << end - start + 1 << endl;
	}

	return 0;
}