// Source: http://stackoverflow.com/questions/6947413/how-to-open-read-and-write-from-serial-port-in-c

#include <errno.h>
#include <fcntl.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

int set_interface_attribs(int fd, int speed);
void set_mincount(int fd, int mcount);

