#include<vector>
#include<fstream>
#include<iostream>
#include<algorithm>
using namespace std;
class stacja{
	public:
	vector <int> g;
	vector <int> t;
	void add(string sg, string st, int b);
	bool zly_pomiar(int nr) const;
	void wypisz() const;
};
stacja St[3];
int ile_rekordow(){
	int w=1;
	int najw[3];
	for(int i=0;i<3;i++) najw[i] = St[i].t[0];
	for(int i=1;i<St[0].g.size();i++){
		bool rekordowy = false;
		for(int a=0;a<3;a++){
			if(St[a].t[i] > najw[a]){
				najw[a] = St[a].t[i];
				rekordowy = true;
			}
		}
		if(rekordowy) w++;
	}
	return w;
}
int z_systemu(string s, int b){
	bool ujemna = false;
	int i=0;
	if(s[0] == '-'){
		ujemna = true;
		i=1;
	}
	int w=0;
	for(;i<s.length();i++){
		w = w * b + (int)s[i] - '0';
	}
	if(ujemna) w*=-1;
	return w;
}
string na_system(int n, int b){
	bool ujemna = false;
	if(n<0){
		ujemna = true;
		n*=-1;
	}
	string w;
	while(n!=0){
		w = (char)(n%b + '0') + w;
		n /= b;
	}
	if(ujemna) w = '-' + w;
	return w;
}
void stacja::add(string sg, string st, int b){
	int sg1 = z_systemu(sg, b);
	int st1 = z_systemu(st, b);
	g.push_back(sg1);
	t.push_back(st1);
}
void stacja::wypisz() const{
	for(int i=0;i<g.size();i++){
		cout<<g[i]<<" "<<t[i]<<endl;
	}
	cout<<endl;
}
int najw_skok(){
	int najww=-1000;
	for(int i=0;i<St[0].t.size();i++){
		for(int j=i+1;j<St[0].t.size();j++){
			int r = (St[0].t[i] - St[0].t[j]) * (St[0].t[i] - St[0].t[j]);
			int odl = (i-j>0)? i-j : (i-j)*(-1);
			int w = (r%odl!=0)? r/odl+1: r/odl;
			if(w > najww) najww = w;
		}
	}
	return najww;
}
int main(){
	//wczytywanie
	ifstream d1;
	d1.open("../../zbior_zadan/58/dane_systemy1.txt");

	string s1, s2;
	while(d1 >> s1 && d1 >> s2){
		St[0].add(s1, s2, 2);
	}
	d1.close();

	d1.open("../../zbior_zadan/58/dane_systemy2.txt");

        while(d1 >> s1 && d1 >> s2){
                St[1].add(s1, s2, 4);
        }
	d1.close();

	d1.open("../../zbior_zadan/58/dane_systemy3.txt");

        while(d1 >> s1 && d1 >> s2){
                St[2].add(s1, s2, 8);
        }
        d1.close();

//rozwiazywanie
//58.1
	/*
	for(int i=0;i<3;i++){
		sort(St[i].t.begin(), St[i].t.end());
		cout<<"Stacja pogodowa nr "<<i+1<<": ";
		cout<<na_system(St[i].t[0], 2)<<endl;
	}
	*/
//58.2
	/*
	int l_z_pomiarow=0;
	int dodane=0;
	for(int i=1;i<St[0].g.size();i++){
		dodane+=24;
		if(St[0].g[i]!= St[0].g[0] + dodane
		&& St[1].g[i]!= St[1].g[0] + dodane
		&& St[2].g[i]!= St[2].g[0] + dodane) l_z_pomiarow++;
	}
	cout<<l_z_pomiarow<<endl;
	*/
//58.3
	/*
	cout<<"liczba rekordowych dni: "<<ile_rekordow()<<endl;
	*/
//58.4
	/*
	cout<<"najwiekszy skok "<< najw_skok()<<endl;
	*/
}
