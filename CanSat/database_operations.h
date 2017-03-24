#include<iostream>
#include<sqlite3.h>


using namespace std;


struct Spectrum
{
	int temperature;
	int preasure;

	int lfl[256];
};