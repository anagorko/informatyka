#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

class Polynomial
{
	vector<double> a;

public:
	Polynomial() : a() {}

	double getA(int n){
		if(n+1>a.size()){
			cout<<"nie dopisal!!!\n";
		}
	return a[n];
	}

	void setA(int n, double v)
	{
		if(n+1>a.size()){
			//cout<<"dopisuje\n";
			a.resize(n+1,0.0);
		}
		a[n]=v;
		return;
	}

	void print(){
		int m=0;
		for(int i=0;i<a.size();i++){		//wypisywanie wielomianu
			if(i==0){		//jeżeli stopnia zerowego
				if(a[0]==0){
				}else{
					cout << a[0];
					m++;
				}
			}
			if(i==1){		//jeżeli stopnia 1
				if(a[1]>0){		//jeżeli wpółczynnik dodatni
					if(a[1]==1){		//jeżeli wpółczynnik=1
						if(a[0]==0){		//jeżeli poprzedniego nie ma
							cout << "x";
							m++;
						}else{		//jeżeli poprzedni jest
							cout << "+x";
						}
					}else{		//jeżeli współczynnik=nie1
						if(a[0]==0){		//jeżeli poprzedniego nie ma
							cout << a[1] << "x";
							m++;
						}else{		//jeżeli poprzedni jest
							cout << "+" << a[1] << "x";
						}
					}
				}
				if(a[1]<0){		//jeżeli współczynnik ujemny
					m++;
					if(a[1]==-1){		//jeżeli wpółczynnik=-1
						cout << "-x";
					}else{		//jeżeli współczynnik=nie-1
						cout << a[1] << "x";
					}
				}
			}
			if(i>1){		//jeżeli stopnia >1
				if(a[i]>0){		//jeżeli współczynnik dodatni
					if(a[i]==1){		//jeżeli wpółczynnik=1
						if(m==0){		//jeżeli nie było wcześniejszych
							cout << "x^" << i;
							m++;
						}else{		//jeżeli były wcześniejsze
							cout << "+x^" << i;
						}
					}else{		//jeżeli współczynnik=nie1
						if(m==0){		//jeżeli nie było wcześniejszych
							cout << a[i] << "x^" << i;
							m++;
						}else{		//jeżeli były wcześniejsze
							cout << "+" << a[i] << "x^" << i;
						}
					}
				}
				if(a[i]<0){		//jeżeli współczynnik ujemny
					m++;
					if(a[i]==-1){		//jeżeli wpółczynnik=-1
						cout << "-x^" << i;
					}else{		//jeżeli współczynnik=nie-1
						cout << a[i] << "x^" << i;
					}
				}
			}
		}
	}
	int d;
	int deg(){
		for(int i=0;i<a.size();i++){
			if(a[i]==0){
			}else{
				d=i;
			}
		}
		cout << endl << "Stopien wielomianu wynosi " << d;
	}
	
	double value(double x){
		double w=a[d]*x+a[d-1];
		for(int i=d-1;i>=0;i--){
			if(i==0){
				w=a[i]*x*w;
			}else{
				w=a[i]*x*w+a[i-1];
			}
		}
		cout << endl << "Wartosc wielomianu wynosi " << w;
		return w;
	}
};

int main(){
	Polynomial p;
	p.setA(0, 0);		//(stopnień, współczynnik) i, a[i]
	p.setA(1, 0);
	p.setA(2, 0);
	p.setA(3, 0);
	p.setA(4, -1);
	p.print();
	p.deg();
	p.value(4);
	return 0;
}
