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

	string magnitudeRepresentation(int) {
		return fullRepresentation();
	}
};

#endif /* __MOMENT__ */	
