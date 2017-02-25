#include<iostream>
using namespace std;

int main()
{
	char c;

	cin >> c;

	switch(c)
	{
		case 'p':
		case 'P':
			cout << "p or P";
			break;
		case '1':
			cout << "1";
		default:
		cout << "d" << endl;
	}
}