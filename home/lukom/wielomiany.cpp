#include <iostream>
#include <vector>
using namespace std;

class Polynomial
{
  vector<double> a;
  int degree;

  public:
    double getA(int n);
    void setA(int n, double x);

    int deg();

    void print();
    double value(double x);

    Polynomial(){
    	degree = -1;
    	a.clear();
    }
    // oraz konstruktory
};
double Polynomial::getA(int n){
    if(degree <= n){
        return a[n];
    }else return 0;
}

void Polynomial::setA(int n, double x){
    if(degree < n){
        a.resize(n+1, 0);
        degree = n;
    }
    a[n] = x;
}

int Polynomial::deg(){
    return degree;
}

void Polynomial::print(){
    bool jcw = false; //już cos wypisałem
	for(int i=degree;i>=0;i--){
		(a[i]!=0) ? cout<< (jcw? "+": "")<<a[i]<<"x^"<<i: "";
        if(!jcw && a[i]!=0) jcw=1;
	}
	cout<<endl;
}
double Polynomial::value(double x){
	double w=a[degree];
	for(int i=degree-1;i>0;i--){
		w=x*w+a[i]*x;
	}
	return w;
}


int main(){
	Polynomial W;
	W.setA(5, 4);
    W.setA(3, 3);
	cout<<"1 element = "<<W.getA(1)<<endl;
	cout<<"deg = "<<W.deg()<<endl;
	cout<<"wyrażenie: ";
	W.print();
	cout<<"dla x=2 wartość wielomiany jest równa: "<<W.value(2)<<endl;
}