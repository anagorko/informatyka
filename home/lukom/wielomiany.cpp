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

    Polynomial& operator+(const Polynomial &q);

    Polynomial(){
    	degree = -1;
    	a.clear();
    }
    // oraz konstruktory
};

Polynomial& Polynomial::operator+(const Polynomial &q){
    for(int i=0;i<=q.degree;i++){
        setA(i, a[i]+q.a[i]);
    }
}
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
		if(a[i]!=0){
            if(a[i]==-1){
                cout<<"-";
            }else if(a[i]==1 && jcw) cout<<"+";
            if(a[i]!=1 && a[i]!=-1) cout<<a[i];
            cout<<"x^"<<i;
            if(!jcw) jcw=1;
        }
	}
	cout<<endl;
}
double Polynomial::value(double x){  // a2x2+a1x+a0 = x(x+a1)a2 + a0
	double w=a[degree];              //  x(x(x+a3)a2)a1+a0
	for(int i=degree-1;i>=0;i--){     // x(x(x(x+a4)a3)a2)a1 + a0
		w=x*w+a[i]*x;
	}
	return w;
}


int main(){
	Polynomial W;
	W.setA(4, 1);
    W.setA(0, 1);
//    W.setA(2, -1);
//    W.setA(1, 1);
	cout<<"wyrażenie W, "<<W.deg()<<" stopnia: "; W.print();
	cout<<"dla x=2 wartość wielomiany jest równa: "<<W.value(2)<<endl<<endl;
    Polynomial Q;
    Q.setA(5, 2);
    Q.setA(3, -1);
    cout<<"wyrażenie Q, "<<Q.deg()<<" stopnia: "; Q.print();
    cout<<"dla x=2 wartość wielomiany jest równa: "<<Q.value(2)<<endl<<endl;
    
    W+Q;
    cout<<"W+Q, to wielomian "<<W.deg()<<" stopnia: "; W.print();
    cout<<endl;
}