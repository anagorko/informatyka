#include <iostream>
#include <fstream>
#include <time.h>
#include <sstream>
#include <unistd.h>//do usleep
#include <string>
using namespace std;
int main(int argc, char* argv[]){
	time_t rawtime;
  	struct tm * timeinfo;
	fstream port;
	fstream plik;

	cout<<"program podaje:\n";
	cout<<"czas <komutera>, rx count, rx millis, tx count, tx millis, payload <smieci>, rssi\n\n";
	string param = "/dev/ttyACM";
	if(argc > 1){
		param += argv[1];
	}else{
		cout<<"podaj jako drugi argument numer portu np. 0, 1, 2, ... \n\n";
		return 0;
	}

	port.open(param.c_str());
	if(!port.is_open()){
		cout<<"nie udało się otworzyć portu\n";
	}
	
	string dane;
	while(getline(port, dane)){
		if(dane.length()==0) continue;
		
		time (&rawtime);
  		timeinfo = localtime (&rawtime);

  		stringstream ss;
  		ss<<timeinfo->tm_hour<<":"<<timeinfo->tm_sec<<","<<dane;
  		dane = ss.str();
		cout<<dane<<endl;
		
		//zapisanie
		plik.open("wyniki.txt", fstream::ate | fstream::out | fstream::in);
		plik << dane << "\n";
		plik.close();
	}
}