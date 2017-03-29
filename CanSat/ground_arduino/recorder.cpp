#include "serial.h"
#include "../datastore/datastore.h"

#include <iostream>
#include <sstream>
using namespace std;

void process_line(string l)
{
}

int main()
{
    string portname = "/dev/ttyACM0";

    int fd;
    int wlen;

    fd = open(portname.c_str(), O_RDWR | O_NOCTTY | O_SYNC);
    if (fd < 0) {
        printf("Error opening %s: %s\n", portname.c_str(), strerror(errno));
        return -1;
    }
    /*baudrate 115200, 8 bits, no parity, 1 stop bit */
    set_interface_attribs(fd, B115200);
    //set_mincount(fd, 0);                /* set to pure timed read */

    /* simple output */
    wlen = write(fd, "Hello!\n", 7);
    if (wlen != 7) {
        printf("Error from write: %d, %d\n", wlen, errno);
    }
    tcdrain(fd);    /* delay for output */


	set_mincount(fd, 1);
    /* simple noncanonical input */

	stringstream ss;
    do {
        unsigned char buf[80];
        int rdlen;

        rdlen = read(fd, buf, sizeof(buf) - 1);
        if (rdlen > 0) {
            buf[rdlen] = 0;
//            printf("Read %d: \"%s\"\n", rdlen, buf);

			for (int i = 0; i < rdlen; i++) {
				ss << buf[i];

				if (buf[i] == '\n') {
					string line;
					getline(ss,line);
					cout << "Got line: " << line << endl;
				}
			}
        } else if (rdlen < 0) {
            printf("Error from read: %d: %s\n", rdlen, strerror(errno));
        } else {
			cout << "loop" << endl;
		}
        /* repeat read to get full message */
    } while (1);
}

