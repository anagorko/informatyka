#include <iostream>
#include <vector>
using namespace std;

class Polynomial
{
  vector<double> a;

  double findRoot(double, double, double);//TODO

  public:
    double getA(int n) const;
    void setA(int n, double x);
    int deg() const;

    Polynomial();
  //  Polynomial(initializer_list<double>);//TODO

    Polynomial& operator+=(const Polynomial &q);
    const Polynomial operator+(const Polynomial &q) const;

    Polynomial& operator-=(const Polynomial &q);
    const Polynomial operator-(const Polynomial &q) const;

    Polynomial& operator*=(const Polynomial &q);
    const Polynomial operator*(const Polynomial &q) const;

    bool operator==(const Polynomial &q) const;    
    bool operator!=(const Polynomial &q) const;

    double v(double x) const;

    friend ostream& operator<<(ostream&, const Polynomial &q);

    const Polynomial differential() const;//TODO

    vector<double> rationalRoots() const;//TODO
    vector<double> realRoots(double) const;//TODO

};

vector<double> Polynomial::rationalRoots() const{
    vector<double> r;
    for(int p=1;p<=getA(0);p++){
        if(getA(0) - (int)getA(0) == 0 && p%(int)getA(0)!=0) continue;
        for(int q=1;q<getA(deg());q++){
            if(getA(deg()) - (int)getA(deg()) == 0 && q%(int)getA(deg())!=0) continue;
            if(v(((double)p)/q)==0) r.push_back( ((double)p)/q);  
        }
    }
    return r;
}

void div(const Polynomial &W, const Polynomial &P, Polynomial &Q, Polynomial &R){
    R = W;                                                                                                                                                                                                              
    for(int i=R.deg();i>=0 && R.deg()>=P.deg();i--){
        Q.setA(i-P.deg(), R.getA(i)/P.getA(P.deg()));
        for(int a=P.deg();a>=0;a--){
            R.setA((i-P.deg())+a, R.getA((i-P.deg())+a)-( P.getA(a) * Q.getA(i-P.deg()) ) ); 
        }
    }                                                                                                                                                                                                                                                                                                                                                                                                                           
}
const Polynomial gcd(const Polynomial &w, const Polynomial &p);//TODO NWD

ostream& operator<<(ostream &os, const Polynomial &q){
    bool jcw = false; //już cos wypisałem
    for(int i=q.deg();i>=0;i--){
        if(q.a[i]!=0){
            if(q.a[i]==-1){
                if(i!=0)os<<"-";
            }else if(q.a[i]>0 && jcw) os<<"+";
            if( i==0 || ( q.a[i]!=1 && q.a[i]!=-1 )) os<<q.a[i];
            if(i!=0) os<<"x^"<<i;
            if(!jcw) jcw=1;
        }
    }
    return os;
}

bool Polynomial::operator!=(const Polynomial &q) const{
    if(deg()!=q.deg()) return true;
    for(int i=0;i<deg();i++){
        if(a[i]!=q.a[i]) return true;
    }
    return false;
}

bool Polynomial::operator==(const Polynomial &q) const{
    if(deg()!=q.deg()) return false;
    for(int i=0;i<deg();i++){
        if(a[i]!=q.a[i]) return false;
    }
    return true;
}

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

double Polynomial::getA(int n) const{
    if(deg() >= n){
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

Polynomial::Polynomial(){
    a.clear();
    setA(0, 0);
}

double Polynomial::v(double x) const{  // a2x2+a1x+a0 = x(x+a1)a2 + a0
    if(deg() == -1) return 0;
	double w=a[deg()];              //  x(x(x+a3)a2)a1+a0
	for(int i=deg()-1;i>=0;i--){     // x(x(x(x+a4)a3)a2)a1 + a0
		w=x*w+a[i]*x;
	}
	return w;
}


int main(){
	Polynomial W, P, Q, R;
//	W.setA(4, 1);
    W.setA(4, 1);
    W.setA(3, 2);
    W.setA(1, 1);
	cout<<"wyrażenie W, "<<W.deg()<<" stopnia: "<<W<<endl;
	cout<<"dla x=2 wartość wielomiany jest równa: "<<W.v(2)<<endl<<endl;
    cout<<"pierwiastki W : ";
    vector<double> r = W.rationalRoots();
    for(int i=0;i<r.size();i++) cout<< r[i]<<" ";
    cout<<endl;
    
    P.setA(4, 1);
    P.setA(3, 2);

    cout<<"wyrażenie P, "<<P.deg()<<" stopnia: "<<P<<endl;
    cout<<"dla x=2 wartość wielomiany jest równa: "<<P.v(2)<<endl<<endl;
    
 //   Q = gcd(W, P);
    cout<<"wyrażenie Q, "<<Q.deg()<<" stopnia: "<<Q<<endl;
    cout<<"dla x=2 wartość wielomiany jest równa: "<<Q.v(2)<<endl<<endl;
}