#include <iostream>
using namespace std;

class BMP
{
	unsigned char* bitmap;
	int w, h, n;

public:
	BMP (int _w, int _h, int _n)
	{
		bitmap = new unsigned char[(_w * _h * _n + 7) / 8];
		w = _w;
		h = _h;
		n = _n;
		for(int i = 0; i < (w*h*n + 7)/8; i++)
		{
			bitmap[i] = (unsigned char) 0;
		}
	}
	void setBit(int bit, bool value)
	{
		int bajt = bit / 8;
			//cout << bajt << endl;
		int bit_w = bit - bajt * 8;
			//cout << bit_w << endl;
		int maska = 128 >> bit_w;
			//cout << maska << endl;
		if(value == 1){
			bitmap[bajt] |= maska;
		}
		else{
			bitmap[bajt] &= ~maska;
		}
			//cout << (int)bitmap[bajt] << endl << endl;
	}
	void setPixel(int x, int y, int k)
	{
		int bajt = n * (y * w + x)/8;
		int bit_w = n * (y * w + x) - bajt * 8;
		int maska = 1 << n - 1;
		while(maska != 0){
			while(bit_w < 8 || maska != 0){

				if((k & maska) != 0){
					cout << maska << endl;
					setBit(bajt * 8 + bit_w, 1);
				}
				if((k & maska) == 0){
					setBit(bajt * 8 + bit_w, 0);
				}			
				bit_w ++;
				maska = maska >> 1;
			}
			bajt += 1;
			bit_w = 0;			
		}
	}
	void save()
	{
		for(int i = 0; i < (w*h*n + 7)/8; i++)
		{
			cout << endl << i << " " << (int)bitmap[i];
		}
	}
};

int main()
{
	BMP p(2, 2, 24);
	//p.setBit(31, 0);
	p.setPixel(0, 0, 237);//TU SIĘ WPISUJE KTÓTY PIKSEL JAK ZMIENIĆ
	p.save();
}
