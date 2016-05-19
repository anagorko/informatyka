#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int n, p, q, start, end, root;
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> p >> q;

		start = 0;
		end = q;

		while(true)
		{
			root = pow( (start + end) / 2, 3 ) + (p * ((start + end) / 2));

			if( root == q )
			{
				root = (start + end) / 2;
				break;
			}
			if( (start == end && root != q) || (start + 1 == end && start != root && end != root))
			{
				root = -1;
				break;
			}
			if( root > q )
			{
				end = (start + end) / 2;
			}
			if( root < q )
			{
				start = (start + end) / 2;
			}
		}

		if(root == -1) cout << "NIE\n";
		else cout << root << endl;
	}

	return 0;
}