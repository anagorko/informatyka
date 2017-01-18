#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
int L[200];
void wczytanie(){
	fstream plik;
	plik.open("../../zbior_zadan/60/liczby.txt");
	for(int i=0;i<200;i++) plik >> L[i];
	plik.close();
}
void pkt1(){
	int mn1000=0;
	int ost1=0;
	int ost2=0;
	for(int i=0;i<200;i++){
		if(L[i] < 1000){
			mn1000++;
			ost1 = ost2;
			ost2 = L[i];
		}
	}
	cout<<"liczb mniejszych niż 1000 jest: "<<mn1000<<endl;
	cout<<"ostatnie dwie takie liczby to: "<<ost1<<" i "<<ost2<<endl;
}
void pkt2(){
	for(int i=0;i<200;i++){
		vector <int> dzielniki;
		for(int j=1;j<=L[i];j++){
			if(L[i]%j==0) dzielniki.push_back(j);
		}
		if(dzielniki.size()==18){
			cout<<"liczba: "<<L[i]<<endl;
			cout<<"dzielniki: ";
			for(int j=0;j<dzielniki.size();j++) cout<<dzielniki[j]<<" ";
			cout<<"\n";
		}
	}
}
void pkt3(){
	bool dzielniki[2][500001];
	for(int i=0;i<500001;i++){
		dzielniki[0][i] = false;
		dzielniki[1][i] = false;
	}
	bool pierwsze[200];
	for(int i=0;i<200;i++){
		pierwsze[i] = true;
		for(int j=2;j<L[i];j++){
			if(L[i]%j==0){
				if(dzielniki[0][j]) dzielniki[1][j] =  true;
				dzielniki[0][j] = true;
			}
		}
	}
	for(int i=0;i<200;i++){
                for(int j=2;j<L[i];j++){
                        if(L[i]%j==0){
                                if(dzielniki[1][j]) pierwsze[i] =  false;
                        }
                }
        }

	int  najwieksza = 0;
	for(int i=0;i<200;i++){
		if(!pierwsze[i]) continue;
		if(L[i] > najwieksza) najwieksza = L[i];
	}
	cout<<"najwieksza liczba wzglednie pierwsza to : "<<najwieksza<<endl;
}
int main(){
	wczytanie();
//60.1
//	pkt1();

//60.2
//	pkt2();

//60.3
	pkt3();
}
