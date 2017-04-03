#ifndef __MOMENT__
#define __MOMENT__

#include<sstream>
#include<iomanip>
using namespace std;

class Moment {
	int moment;

public:
	Moment(int m) {
		moment = m;
	}

	string fullRepresentation() {
		int m = moment;
		int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		string day_name[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
		string month_name[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Sep", "Oct", "Nov", "Dec" };

		stringstream ss;

		ss << "2017-";

		int mo = 0;
		while (m > days[mo] * 24 * 60 * 60 * 10 && mo < 12) {
			m = m - days[mo] * 24 * 60 * 60 * 10; mo++;
		}

		if (mo == 12) return "Date out of range";

		ss << month_name[mo] << "-";

		int da = m / (24*60*60*10); m = m % (24*60*60*10);

		ss << setw(2) << setfill('0') << (da+1) << " ";

		int h = m / (60*60*10); m = m % (60*60*10);
		ss << setw(2) << setfill('0') << h << ":";

		int mi = m / (60*10); m = m % (60*10);
		ss << setw(2) << setfill('0') << mi << ":";

		int s = m /10; m = m % 10;
		ss << setw(2) << setfill('0') << s << "." << setw(1) << m;

		string line; getline(ss,line);

		return line;
	}

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

	string magnitudeRepresentation(int) {
		return fullRepresentation();
	}
};

#endif /* __MOMENT__ */	
