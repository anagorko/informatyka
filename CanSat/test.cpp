#include"database_operations.h"

using namespace std;

int main()
{
	spectrum s;

	s = lastRecord();

	cout << s.temperature << endl << endl;
}