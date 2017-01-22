#include<iostream>
#include<vector>
#include<fstream>
#include<string>
using namespace std;
class genotyp {
	public:
	string s;
	bool odporny_na_zmeczenie() const;
	int ilosc_genow() const;
	int jaki_najdluzszy_gen() const;
	bool silnie_odporny() const;
	bool odporny() const;
	vector <string> geny(string s1) const;
}M[1000];
bool genotyp::odporny() const {
	vector <string> v = geny(s);
	string s1;
	for(int i=s.length()-1;i>=0;i--) s1+=s[i];
	vector <string> v1 = geny(s1);
	string g,g1;
	for(int i=0;i<v.size();i++) g+=v[i];
        for(int i=0;i<v1.size();i++) g1+=v1[i];
	if(g1 == g) return true;
	else return false;
}
bool genotyp::silnie_odporny() const {
	for(int i = 0;i<s.length()/2;i++){
		if(s[i] != s[s.length()-1-i]) return false;
	}
	return true;
}
int genotyp::jaki_najdluzszy_gen() const {
	vector <string> v = geny(s);
	int wmax = 0;
	for(int i =0;i<v.size();i++) if(v[i].length() > wmax) wmax = v[i].length();
	return wmax;
}
int genotyp::ilosc_genow() const{
	return geny(s).size();
}
vector <string> genotyp::geny(string s1) const {
	vector <string> v;
	bool znalazlem_poc = false;
	bool znalazlem_kon = false;
	for(int i=0;i<s1.length();i++){
		while(i < s1.length()-1){
			if(s1.substr(i,2) == "AA"){
				znalazlem_poc = true;
				break;
			}else i++;
		}
		int j = i;
		while(j < s1.length()-1){
			if(s1.substr(j,2) == "BB"){
				znalazlem_kon = true;
				j+=1;
				break;
			}else j++;
		}
		if(znalazlem_poc && znalazlem_kon){
			v.push_back(s1.substr(i, j-i+1));
			//cout<<v[v.size()-1]<<endl;
			znalazlem_poc = false;
			znalazlem_kon = false;
		}
	}
	return v;
}
bool genotyp::odporny_na_zmeczenie() const {
	string G = "BCDDC";
	vector <string> v = geny(s);
	for(int i=0;i<v.size();i++){
		for(int j=2;j<v[i].length() - 4;j++){
			if(v[i].substr(j,5) == G) return true;
		}
	}
	return false;
}
void wczytanie(){
	fstream plik;
	plik.open("../../zbior_zadan/69/dane_geny.txt");
	for(int i =0;i<1000;i++){
		plik >> M[i].s;
	//	cout << M[i].s<<endl;
	}
	plik.close();
}
void pyt1(){
	int dl[501];
	for(int i=0;i<501;i++) dl[i] = 0;
	for(int i=0;i<1000;i++) dl[M[i].s.length()]++;
	int ile=0;
	int maxil = 0;
	for(int i=0;i<501;i++){
		if(dl[i] > 0) ile++;
		if(maxil < dl[i]) maxil = dl[i];
	}
	cout<<"jest "<<ile<<" gatunkow"<<endl;
	cout<<"maksymalna liczba reprezentantow gatunku: "<<maxil<<endl;
}
void pyt2(){
	int w = 0;
	for(int i=0;i<1000;i++) if(M[i].odporny_na_zmeczenie()) w++;
	cout<<w<<" osobnikow jest odpornych na zmeczenie\n";
}
void pyt3(){
	int dlmax = 0;
	int ilmax = 0;
	for(int i=0;i<1000;i++){
		if(ilmax < M[i].ilosc_genow()) ilmax = M[i].ilosc_genow();
		if(dlmax < M[i].jaki_najdluzszy_gen()) dlmax = M[i].jaki_najdluzszy_gen();
	}
	cout<<"najwieksza liczba genow: "<<ilmax<<endl;
	cout<<"najdluzszy gen: "<<dlmax<<endl;
}
void pyt4(){
	int so=0;
	int o =0;
	for(int i =0;i<1000;i++){
		if(M[i].silnie_odporny())so++;
		else if(M[i].odporny())o++;
	}
	cout<<"odpornych jest: "<<o<<endl;
	cout<<"silnie odpornych jest: "<<so<<endl;
}
int main(){
	wczytanie();
//	pyt1();
//	pyt2();
//	pyt3();
//	pyt4();
}

