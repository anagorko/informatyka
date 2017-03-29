#include <iostream>
#include <fstream>
using namespace std;
class BMP {
	unsigned char *bitmap;
	int width, heigh, count_pix;
public:
	BMP(int width, int heigh, int count_pix);
	bool bitValue(char bajt, int miejsce) const;
	void wypiszBity(char bajt) const;
	void setBit(int offset, bool value);
	iostream& operator << (iostream&) const;

}X(12,12,12);

ostream& operator << (ostream& os, BMP B);

ostream& operator << (ostream& os, BMP B) {
	//nagłówek
	os << "B"<<"M";
	int a  = 17;
	//size of file
	os << (char)a << (char)(a << 8) << (char)(a << 16) << (char)(a << 24);
	//waste
	os << "00" << "00";
	//offset where the bitmap can be found
	a = 11;
	os << (char)a << (char)(a << 8) << (char)(a << 16) << (char)(a << 24);
	//set pixels
	int r = 255;
	int g = 0;
	int b = 0;
	a = r;
	os << (char)0b11111111 << (char)0b00000000 << (char)0b00000000;
}

BMP::BMP(int width, int heigh, int count_pix){
	this -> width = width;
	this -> heigh = heigh;
	this -> count_pix = count_pix;
	bitmap = new unsigned char[(width * heigh * count_pix+7)/8]; 
}

bool BMP::bitValue(char bajt, int miejsce) const {
	return ((bajt & (1 << miejsce)) == 0)?  0: 1;
}

void BMP::wypiszBity(char bajt) const {
	for(int i=7;i>=0;i--){
		cout<<bitValue(bajt,i)<<" ";
	}
	cout<<"\n";
}

void BMP::setBit(int offset, bool value) {
	bitmap[0] = 0b01010011;
	int numer_bajtu = offset/8;
	int miejsce_w_bajcie = offset%8;
		
	bool bit = bitValue(bitmap[numer_bajtu],miejsce_w_bajcie);
		
	//wypiszBity(bitmap[numer_bajtu]);

	if(bit == 0 && value == 1){
		bitmap[numer_bajtu] = ( bitmap[numer_bajtu] | (1 << miejsce_w_bajcie));
	}else if(bit == 1 && value == 0){
		bitmap[numer_bajtu] = ~( ( ~bitmap[numer_bajtu] ) | (1 << miejsce_w_bajcie) );
	}
		
	//wypiszBity(bitmap[numer_bajtu]);
}
void saveToFile(){
	ofstream plik;
	plik.open("plik.bmp");
	plik << X;
	plik.close();
}

int main(){
	X.setBit(1, 0);
	saveToFile();
}