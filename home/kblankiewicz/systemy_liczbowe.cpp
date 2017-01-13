#include <iostream>
#include <cmath>
using namespace std;

string q = "0123456789ABCDEF";
int s1[1095][2];
int s2[1095][2];
int s3[1095][2];

char szukaj(int z)
{
	return q[z];
}

string nasystem(int n, int b)
{	
	string s = "";
	int np = abs(n);
	int z;
	while(np != 0)
	{
		z = np % b;
		s = szukaj(z) + s;
		np = np/b;
	}
	if(n >=0)
	{
		return s;
	}
	else
	{
		string v = "-" + s;
		return v;
	}
}

int zsystemu(string d, int b)
{
	string s;
	if(d[0] != '-'){
		s = d;
	}
	else{
		for(int i = 1; i < d.length(); i++){
			s = s + d[i];
		}
	}
	int x = 0;
	for(int i = 0; i < s.length(); i++)
	{
		for(int j = 0; j < 16; j++)
		{
			if(s[i] == q[j])
			{
				x = x * b;
				x = (x + j);
				break;
			}
		}
	}
	if(d[0] != '-'){
		return x;
	}
	else{
		return -x;
	}
}

int najzimniej(int t[1095][2]) //zwraca najmniejszą temperaturę ze stacji
{
	int p =  t[0][1];
	for(int i  = 0; i < 1095; i++){
		if(t[i][1] < p){
			p = t[i][1];
		}
	}
	return p;
}	

bool kontrolagodziny(int godzina, int numerpomiaru)
{
	if(godzina == 12 + numerpomiaru * 24 ) return true;
	else return false;
}

int podpunkt3 ()
{
	int r1 = 0;
	int r2 = 0;
	int r3 = 0;
	int f = 0;
	for(int i = 0; i < 1095; i++){
		if(s1[i][1] > r1){
			r1 = s1[i][0];
			f += 1;
		}else{
			if(s2[i][1] > r2){
				r2 = s2[i][0];
				f += 1;
			}else{
				if(s3[i][1] > r3){
					r3 = s3[i][0];
					f += 1;
				}
			}
		}
	}
	return f;
}

int main()
{

	//ładowanie danych
	string x;
	string y;
	int b;
	for(int i = 0; i < 1095; i++){
		b = 2;
		cin >> x;
		cin >> y;
		s1[i][0] = zsystemu(x, b);
		s1[i][1] = zsystemu(y, b);
	}
	for(int i = 0; i < 1095; i++){
		b = 4;
		cin >> x;
		cin >> y;
		s2[i][0] = zsystemu(x, b);
		s2[i][1] = zsystemu(y, b);
	}
	for(int i = 0; i < 1095; i++){
		b = 8;
		cin >> x;
		cin >> y;
		s3[i][0] = zsystemu(x, b);
		s3[i][1] = zsystemu(y, b);
	}

	//58.1

	cout<< "Kontrola:"<< endl <<s1[0][0]<<"  "<<s1[0][1] << endl << s2[0][0] <<"  "<< s2[0][1] << endl << s3[0][0] <<"  "<< s3[0][1] <<endl<<endl;

	cout<< "58.1"<< endl << nasystem(najzimniej(s1), 2)<< endl << nasystem(najzimniej(s2), 2)<< endl << nasystem(najzimniej(s3), 2)<< endl;

	//58.2:	
	
	int d = 0;
	for(int i = 0; i < 1095; i++){
		if(kontrolagodziny(s1[i][0], i ) == false && kontrolagodziny(s2[i][0], i ) == false && kontrolagodziny(s3[i][0], i) == false){
			d += 1;
		}
	}
	cout << endl << "58.2" << endl << d << endl;

	//58.3
	
	cout << endl << "58.3" << endl << podpunkt3() << endl;
}
