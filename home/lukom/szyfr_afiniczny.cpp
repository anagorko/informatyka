#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
string zaszyfrowane(string s, int a, int b){
	string w;
	for(int i=0;i<s.length();i++){
		int liczba = s[i] - 'a';
		w+=( ( liczba * a + b ) % 26 ) + 'a';
	}
	return w;
}
string odszyfrowane(string s, int a, int b){
	string w;
	for(int i=0;i<s.length();i++){
		int liczba = ( s[i] - 'a' - b )%26;
		if(liczba < 0) liczba+=26;
		if(liczba%a!=0) return "-1";
		 w+= (liczba/a) + 'a';
	}
	return w;
}
vector <string> T,P[2];
void wczytanie(){
	fstream plik;
	plik.open("../../zbior_zadan/75/tekst.txt");
	for(int i=0;i<805;i++){
		string s;
		plik >> s;
		T.push_back(s);
	}
	plik.close();
	plik.open("../../zbior_zadan/75/probka.txt");
	for(int i=0;i<5;i++){
		string s,s1;
		plik >> s;
		P[0].push_back(s);
		plik >> s1;
		P[1].push_back(s1);
		cout<<P[0][i]<<" "<<P[1][i]<<endl;
	}
}
void pyt1(){
	for(int i=0;i<T.size();i++){
		if(T[i][0] == 'd' && T[i][T[i].length()-1] == 'd') cout<<T[i]<<endl;
	}
}
void pyt2(){
	for(int i=0;i<T.size();i++){
		if(T[i].length()>=10) cout<<zaszyfrowane(T[i],5,2)<<endl;
	}
}
void pyt3(){
	for(int i=0;i<5;i++){
		int az = -1,bz = -1;
		int ao = -1,bo = -1;
		for(int j=1;j<26;j++){
			for(int q=0;q<26;q++){
				if(zaszyfrowane(P[0][i],j,q) == P[1][i]){
					az = j;
					bz = q;
				}
				if(zaszyfrowane(P[1][i],j,q) == P[0][i]){
					ao = j;
					bo = q;
				}
			}
		}
		cout<<"kod szyfrujacy: "<<az<<" "<<bz<<endl;
		cout<<"kod deszyfrujacy: "<<ao<<" "<<bo<<endl;
	}
}
int main(){
	wczytanie();
//	pyt1();
//	pyt2();
//	pyt3();
}
