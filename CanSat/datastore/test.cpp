#include<iostream>

using namespace std;

int time_to_moment( string time )
{
	int year = 0, month = 0, day = 0, hour = 0, minute = 0, second = 0, moment = 0;

	int controler = 0;

	for ( int i = 0; i < time.size(); i++ )
	{
		if ( time[i] == '-' || time[i] == ':' || time[i] == ' ' || time[i] == '.' )
			controler++;
		else
		{
			switch ( controler )
			{
				case 0:
					year = year * 10 + ( (int) time[i] - '0' );
					break;
				case 1:
					month = month * 10 + ( (int) time[i] - '0' );
					break;
				case 2:
					day = day * 10 + ( (int) time[i] - '0' );
					break;
				case 3:
					hour = hour * 10 + ( (int) time[i] - '0' );
					break;
				case 4:
					minute = minute * 10 + ( (int) time[i] - '0' );
					break;
				case 5:
					second = second * 10 + ( (int) time[i] - '0' );
					break;
				case 6:
					moment = moment * 10 + ( (int) time[i] - '0' );
					break;
			}
		}
	}

	struct tm now, zero;
	
	zero.tm_year = 117;
	zero.tm_mon = 0;
	zero.tm_mday = 1;
	zero.tm_hour = 0;
	zero.tm_min = 0;
	zero.tm_sec = 0;
	zero.tm_isdst = -1;

	now.tm_year = year - 1900;
	now.tm_mon = month - 1;
	now.tm_mday = day;
	now.tm_hour = hour;
	now.tm_min = minute;
	now.tm_sec = second;
	now.tm_isdst = -1;

	time_t now_mk = mktime(&now), zero_mk = mktime(&zero);
	
	int time_return = ( ( difftime( now_mk, zero_mk ) * 10 ) + moment );

	return time_return;
}


int time_to_moment2( string time )
{
	int year = 0, month = 0, day = 0, hour = 0, minute = 0, second = 0, moment = 0;

	int controler = 0;

	for ( int i = 0; i < time.size(); i++ )
	{

		if ( time[i] == '-' || time[i] == ':' || time[i] == ' ' || time[i] == '.' )
			controler++;
		else
		{
			switch ( controler )
			{
				case 0:
					year = year * 10 + ( (int) time[i] - '0' );
					break;
				case 1:
					month = month * 10 + ( (int) time[i] - '0' );
					break;
				case 2:
					day = day * 10 + ( (int) time[i] - '0' );
					break;
				case 3:
					hour = hour * 10 + ( (int) time[i] - '0' );
					break;
				case 4:
					minute = minute * 10 + ( (int) time[i] - '0' );
					break;
				case 5:
					second = second * 10 + ( (int) time[i] - '0' );
					break;
				case 6:
					moment = moment * 10 + ( (int) time[i] - '0' );
					break;
			}
		}
	}

	struct tm now, zero;
	
	zero.tm_year = 117;
	zero.tm_mon = 0;
	zero.tm_mday = 1;
	zero.tm_hour = 0;
	zero.tm_min = 0;
	zero.tm_sec = 0;
	zero.tm_isdst = -1;

	now.tm_year = year - 1900;
	now.tm_mon = month - 1;
	now.tm_mday = day;
	now.tm_hour = hour;
	now.tm_min = minute;
	now.tm_sec = second;
	now.tm_isdst = -1;

cout << zero.tm_year << " " << now.tm_year << endl;
cout << zero.tm_mon << " " << now.tm_mon << endl;
cout << zero.tm_mday << " " << now.tm_mday << endl;
cout << zero.tm_hour << " " << now.tm_hour << endl;
cout << zero.tm_min << " " << now.tm_min << endl;
cout << zero.tm_sec << " " << now.tm_sec << endl;

	time_t now_mk = mktime(&now), zero_mk = mktime(&zero);

cout << now_mk << " " << zero_mk << endl;

	int time_return = ( ( difftime( now_mk, zero_mk ) * 10 ) + moment );

	return time_return;
}


int main()
{
	string s = "2017-01-01 00:00:05.0";

	cout << time_to_moment( s ) << endl;
	cout << time_to_moment2( s ) << endl;;
}
