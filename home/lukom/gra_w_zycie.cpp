#include<iostream>
using namespace std;
const int n=12,m=20;
class plansza {
public:
	string t[n];
	string tp[n];
	void nstep();
	int spkt(int x, int y);
	void draw();
	int szyw();


};
int plansza::szyw(){
	int s=0;
	for(int i=0;i<n;i++){
		for(int a=0;a<m;a++){
			if(t[i][a] == 'X') s++;
		}
	}
	return s;
}
void plansza::draw(){
	for(int i=0;i<n;i++){
		cout<<t[i]<<endl;
	}
	cout<<endl;
}
int plansza::spkt(int x, int y){
	int s = 0;
	for(int i=((x+m-1)%m);i<((x+2)%m);i++){
		if(t[(y+n-1)%n][i]=='X')s++;
		if(t[(y+1)%n][i]=='X')s++;
	}
	if(t[y][((x+m-1)%m)] == 'X') s++;
	if(t[y][((x+1)%m)] == 'X') s++;
	return s;
}
void plansza::nstep(){
	string t1[n];
	for(int i=0;i<n;i++){
		for(int a=0;a<m;a++){
			if(t[i][a]=='X'){
				if(spkt(a,i) == 2 || spkt(a,i) == 3) t1[i] += 'X';
				else t1[i] += '.';
			}else{
				if(spkt(a,i) == 3) t1[i] += 'X';
				else t1[i] += '.';
			}
		}
	}
	for(int i=0;i<n;i++){
		tp[i] = t[i];
		 t[i] = t1[i];
	}
}

int main(){
	plansza P;
	//wczytywanie
	for(int i=0;i<n;i++) cin>>P.t[i];

	P.draw();
	bool juz_powiedzialem = false;
	for(int i=0;i<100;i++){
		P.nstep();
//		P.draw();
		if(i==36) cout<<"Sasiedzi w 37 pokoleniu punktu (2,19): "<< P.spkt(1,18)<<endl;
		if(i==1) cout<<"żywych komórek w drugim pokoleniu: "<<P.szyw()<<endl;;
		bool takie_samo = true;
		for(int q=0;q<n;q++){
			if(P.tp[q] != P.t[q]) takie_samo=false;
		}
		if(!juz_powiedzialem && takie_samo){
			cout<<"układ się ustalił w pokoleniu ";
			cout<<i+1<<endl;
			cout<<"liczba zywych komórek to: "<<P.szyw()<<endl;
			juz_powiedzialem = true;
		}
	}

}
