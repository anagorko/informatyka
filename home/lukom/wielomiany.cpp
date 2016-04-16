#include <iostream>
#include <vector>
using namespace std;

class Polynomial
{
  vector<double> a;
  

  public:
    double getA(int n);
    void setA(int n, double x);

    int deg() const;

    void print();
    double value(double x);

    Polynomial& operator+=(const Polynomial &q);
    const Polynomial operator+(const Polynomial &q) const;

    Polynomial& operator-=(const Polynomial &q);
    const Polynomial operator-(const Polynomial &q) const;

    Polynomial& operator*=(const Polynomial &q);
    const Polynomial operator*(const Polynomial &q) const;

    Polynomial(){
        a.clear();
    	setA(0, 0);
    }
    Polynomial(int n){
        a.resize(n+1, 0.0);
    }


    // oraz konstruktory
};

const Polynomial Polynomial::operator*(const Polynomial &q) const{
    Polynomial _a;

    for(int x=0;x<=q.deg();x++){
        for(int y=0;y<=deg();y++){
            _a.setA(x+y, (x+y<=_a.deg()?_a.a[x+y]:0) + a[y]*q.a[x] );
        }
    }
    _a.deg();
    return _a;
}
Polynomial& Polynomial::operator*=(const Polynomial &q){
    Polynomial _a;

    for(int x=0;x<=q.deg();x++){
        for(int y=0;y<=deg();y++){
            _a.setA(x+y, (x+y<=_a.deg()?_a.a[x+y]:0) + a[y]*q.a[x] );
        }
    }
    (*this) = _a;
}

const Polynomial Polynomial::operator-(const Polynomial &q) const{
    Polynomial _a;
    for(int i=0;i<=q.deg();i++){
        _a.setA(i, (i<=deg()?a[i]:0)-q.a[i]);
    }
    _a.deg();
    return _a;
}
Polynomial& Polynomial::operator-=(const Polynomial &q){
    for(int i=0;i<=q.deg();i++){
        setA(i, (i<=deg()?a[i]:0)-q.a[i]);
    }
    deg();
}

const Polynomial Polynomial::operator+(const Polynomial &q) const{
    Polynomial _a;
    for(int i=0;i<=q.deg();i++){
        _a.setA(i, (i<=deg()?a[i]:0)+q.a[i]);
    }
    _a.deg();
    return _a;
}
Polynomial& Polynomial::operator+=(const Polynomial &q){
    for(int i=0;i<=q.deg();i++){
        setA(i, (i<=deg()?a[i]:0)+q.a[i]);
    }
    deg();
}

double Polynomial::getA(int n){
    if(deg() <= n){
        return a[n];
    }else return 0;
}

void Polynomial::setA(int n, double x){ 
    if(deg() < n){
        a.resize(n+1, 0);
    }
    a[n] = x;
}

int Polynomial::deg() const{
    int _a = a.size()-1;
    for(int i=a.size()-1;i>=0;i--){
        if(a[i]!=0) break;
        _a--;
    }
    return _a;
}

void Polynomial::print(){
    bool jcw = false; //już cos wypisałem
	for(int i=deg();i>=0;i--){
		if(a[i]!=0){
            if(a[i]==-1){
                if(i!=0)cout<<"-";
            }else if(a[i]>0 && jcw) cout<<"+";
            if( i==0 || ( a[i]!=1 && a[i]!=-1 )) cout<<a[i];
            if(i!=0)cout<<"x^"<<i;
            if(!jcw) jcw=1;
        }
	}
	cout<<endl;
}
double Polynomial::value(double x){  // a2x2+a1x+a0 = x(x+a1)a2 + a0
    if(deg() == -1) return 0;
	double w=a[deg()];              //  x(x(x+a3)a2)a1+a0
	for(int i=deg()-1;i>=0;i--){     // x(x(x(x+a4)a3)a2)a1 + a0
		w=x*w+a[i]*x;
	}
	return w;
}


int main(){
	Polynomial W;
//	W.setA(4, 1);
//    W.setA(0, 1);
//    W.setA(2, -1);
//    W.setA(1, 1);
	cout<<"wyrażenie W, "<<W.deg()<<" stopnia: "; W.print();
	cout<<"dla x=2 wartość wielomiany jest równa: "<<W.value(2)<<endl<<endl;
    Polynomial Q;
    
    Q.setA(4, -1);
    Q.setA(3, 2);
    cout<<"wyrażenie Q, "<<Q.deg()<<" stopnia: "; Q.print();
    cout<<"dla x=2 wartość wielomiany jest równa: "<<Q.value(2)<<endl<<endl;
    
    W += Q;
    cout<<"W+=Q, to wielomian "<<W.deg()<<" stopnia: "; W.print();
    cout<<endl;
}