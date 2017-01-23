#include<iostream>
#include<math.h>
using namespace std;
double f(double x){
	return (x*x*x*x)/500 - (x*x)/200 - 3/250;
}
double g(double x){
	return -(x*x*x)/30 + x/20 + 1/6;
}
class punkt {
	public:
	double x,y;
};
class zaslona{
	public:
	punkt A,B,C,D;
	zaslona();
	double powierzchnia_reszty() const;
	double obwod() const;
	int dlugosc_pasow() const;
}Z;
int zaslona::dlugosc_pasow() const {
	int dl=0;
	for(double i= C.x - 0.25; i > D.x ;i-=0.25){
		dl +=(int) ( 0.25 * (f(i)-g(i)) );
	}
	return dl;
}
double zaslona::obwod() const {
	double Obw = 0;
	Obw += D.y + (C.x - D.x);
	Obw += A.y + (B.x - A.x);
	for(int i = 1; i < 1000; i++){
		punkt E,F;
		double x1,x2;
		x1 = A.x + (i-1)/1000 * (B.x - A.x);
		x2 = A.x + i/1000 * (B.x - A.x);
		Obw += sqrt( (x2 - x1)*(x2 - x1) + (f(x2) - f(x1))*(f(x2) - f(x1)) );
		Obw += sqrt( (x2 - x1)*(x2 - x1) + (-g(x2) + g(x1))*(-g(x2) + g(x1)) );
	}
	return Obw;
}
double zaslona::powierzchnia_reszty() const {
	double P=0;
//	P = D.y * (C.x - D.x);
//	P += -A.y * (B.x  - A.x);
	for(int i=1;i<1000;i++){
		P += f(C.x - i/1000 * (C.x - D.x)) * 1/1000 * (C.x - D.x) + ( f(C.x - (i-1)/1000 * (C.x - D.x)) - f(C.x - i/1000 * (C.x - D.x)) ) * 1/500;
		P += -g(B.x - i/1000 * (B.x - A.x)) * 1/1000 * (B.x - A.x) + ( -g(B.x - (i-1)/1000 * (B.x - A.x)) + g(B.x - i/1000 * (B.x - A.x)) ) * 1/500;
	}
	return P;
}
zaslona::zaslona(){
	A.x = 2;
	A.y = g(10);
	B.x = 10;
	B.y = g(10);
	C.x = 10;
	C.y = f(10);
	D.x = 2;
	D.y = f(10);
}
void pyt1(){
	cout<<Z.powierzchnia_reszty()<<endl;
}
void pyt2(){
	int obw = (int)Z.obwod();
	if(Z.obwod() != obw) obw = (int) obw +1;
	cout<<obw<<endl;
}
void pyt3(){
	cout<<Z.dlugosc_pasow()<<endl;
}
int main(){
//	pyt1();
//	pyt2();
//	pyt3();
}
