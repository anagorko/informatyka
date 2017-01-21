#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int z_systemu(string l, int b){
        int w = 0;
        for(int i=0; i < l.size(); i++){
                w  = w*b + (int)l[i] - '0';
        }
        return w;
}
string na_system( int l, int b){
        string w;
        while(l != 0){
                w = (char)((l%b) + '0') + w;
                l/=b;
        }
        return w;
}
class fraktal {
	public:
	string W[40];
	fraktal();
	void wypisz();
	bool pierwsza(int n) const;
}F;
bool fraktal::pierwsza(int n) const {
	int liczba = z_systemu(W[n],2);
	for(int i=2;i<=sqrt(liczba);i++){
		if((liczba%i)==0) return false;
	}
	return true;
}
void fraktal::wypisz(){
	for(int i=0;i<40;i++){
		cout<<W[i]<<"\n";
	}
}
fraktal::fraktal(){
	W[0] = "1";
	W[1] = "1";
	for(int i=2;i<40;i++) {
		int liczba = z_systemu(W[i-1],2) + z_systemu(W[i-2],2);
		W[i] = na_system(liczba,2);
	}
	//uzupełnienie zerami:
	for(int i=0;i<40;i++){
                if(W[i].length() < W[39].length()){
			int dl =W[39].length() - W[i].length();
                        for(int j=0;j < dl;j++){
				W[i] = '0' + W[i];
			}
                }
	}

}
void pyt1(){
	for(int i=10;i<=40;i+=10){
		cout<<"F"<<i<<" = ";
		cout<<z_systemu(F.W[i-1],2)<<endl;
	}
}
void pyt2(){
	for(int i=0;i<40;i++){
		if(F.pierwsza(i))cout<<z_systemu(F.W[i],2)<<endl;
	}
}
void pyt3(){
	F.wypisz();
}
void pyt4(){
	for(int i=0;i<40;i++){
		int sum = 0;
		for(int j=0;j<F.W[i].length();j++) sum += (int)F.W[i][j] - '0';
		if(sum == 6) cout<<na_system(z_systemu(F.W[i],2),2)<<endl;
	}
}

int main(){
//	F.wypisz();
//	pyt1();
//	pyt2();
//	pyt3();
//	pyt4();
}

