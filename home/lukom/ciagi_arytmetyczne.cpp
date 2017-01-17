#include<iostream>
#include<vector>
#include<fstream>
#include<math.h>
using namespace std;
class ciag{
	public:
	int n;
	vector <int> t;
	bool czy_ciag() const;
}C[100], B[20];
bool ciag::czy_ciag() const {
	for(int i=2;i<n;i++){
		if(t[i]-t[i-1] != t[1] - t[0] ) return false;
	}
	return true;
}
void wczytywanie(){
	fstream plik;
	plik.open("../../zbior_zadan/61/ciagi.txt");
	for(int i=0;i<100;i++){
		plik >> C[i].n;
		for(int j=0;j<C[i].n;j++){
			int l;
			plik>>l;
			C[i].t.push_back(l);
		}
	}
	plik.close();
	plik.open("../../zbior_zadan/61/bledne.txt");
	for(int i=0;i<20;i++){
		plik >> B[i].n;
		for(int j=0;j < B[i].n;j++){
			int l;
			plik >> l;
			B[i].t.push_back(l);
		}
	}
	plik.close(); 
}
void pkt1(){
	int ile=0;
	int najw_roznica = 0;
	for(int i=0;i<100;i++){
		if(C[i].czy_ciag()){
			 ile++;
			if(najw_roznica < C[i].t[1] - C[i].t[0]) najw_roznica = C[i].t[1] - C[i].t[0];
		}
	}
	cout<<ile<<" spośród podanych ciągów jest ciągami arytmetycznymi"<<endl;
	cout<<"najwieksza różnica ciągu arytmetycznego to: "<<najw_roznica<<endl;
}
bool czy_szescian(int liczba){
	for(int i=2;i<liczba;i++){
		if(i*i*i == liczba) return true;
	}
	return false;
}
void pkt2(){
	for(int i=0;i<100;i++){
		int najw = -1;
		for(int j=0;j<C[i].n;j++){
			if(czy_szescian(C[i].t[j])) najw = C[i].t[j];
		}
		if(najw != -1) cout<<najw<<endl;
	}
}
void pkt3(){
	for(int i=0;i<20;i++){
		int r= (B[i].t[1]-B[i].t[0] == B[i].t[2]-B[i].t[1])? B[i].t[1] - B[i].t[0] : B[i].t[4] - B[i].t[3];
		for(int j=1;j<B[i].n;j++){
			if(B[i].t[j] - B[i].t[j-1] != r){
				if(i==1){
					if(B[i].t[2] - B[i].t[1] != r) cout<<B[i].t[1]<<endl;
					else cout<<B[i].t[0]<<endl;
				}else cout<<B[i].t[j]<<endl;
				break;
			}
		}
	}
}


int main(){
	wczytywanie();
//	pkt1();
//	pkt2();
//	pkt3();
}
