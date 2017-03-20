#include <iostream>
using namespace std;
class BMP {
	unsigned char *bitmap;
	int width, heigh, count_pix;
public:
	BMP(int width, int heigh, int count_pix){
		this -> width = width;
		this -> heigh = heigh;
		this -> count_pix = count_pix;
		bitmap = new unsigned char[(width * heigh * count_pix+7)/8]; 
	}
	bool bitValue(char bajt, int miejsce){
		return ((bajt & (1 << miejsce)) == 0)?  0: 1;
	}
	void wypiszBity(char bajt){
		for(int i=7;i>=0;i--){
			cout<<bitValue(bajt,i)<<" ";
		}
		cout<<"\n";
	}
	void setBit(int offset, bool value){
		bitmap[offset] = 1;//0b00000001; 
		int numer_bajtu = offset/8;
		int miejsce_w_bajcie = offset%8;
		bool bit = bitValue(bitmap[numer_bajtu],miejsce_w_bajcie);
		wypiszBity(bitmap[numer_bajtu]);
		if(value == 1 && bit == 0){
			bitmap[numer_bajtu] = ( (~bitmap[numer_bajtu]) & (1 << miejsce_w_bajcie));
		}else if(value == 0 && bit == 1){
			bitmap[numer_bajtu] = (bitmap[numer_bajtu] & (1 << miejsce_w_bajcie));
		}
	}
	
	//&iostream operator << (&iostream);
}X(12,12,12);
int main(){
	X.setBit(0, 1);
};