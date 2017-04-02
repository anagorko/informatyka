#include<iostream>

using namespace std;

string moment_to_time( int moment )
{
	struct tm zero;
	zero.tm_year = 117;
	zero.tm_mon = 0;
	zero.tm_mday = 1;
	zero.tm_hour = 0;
	zero.tm_min = 0;
	zero.tm_sec = 0;

	time_t now = mktime( &zero ) + ( moment / 10 );

	char buff[100];
	strftime(buff, 100, "%Y-%m-%d %H:%M:%S", localtime( &now ) );

	string s = buff;

	return s + '.' + (char) ( (moment % 10) + '0' );
}

int main()
{
	cout << moment_to_time(1) << endl;
}
