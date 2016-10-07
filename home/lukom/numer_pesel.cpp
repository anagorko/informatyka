#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
class pesel{
public:
	string p;
	bool czyGru() const;
	bool czyK() const;

};
bool pesel::czyGru() const {
	if(p.substr(2,2)=="12") return true;
	else return false;
}
bool pesel::czyK() const{
	if((p[9]%2)==0) return true;
	else return false;
}
bool operator<(pesel p1, pesel p2){
	if(p1.p.substr(0,2) < p2.p.substr(0,2)) return true;
	else return false;
}
int main(){
	vector <pesel> V;
	string in;
	fstream pes;
	pes.open("pesel.txt", ios::in);
	while(pes>>in){
		pesel p;
		p.p = in;
		V.push_back(p);
	}
	int ur10=0;
	int ilek=0;
	int t[12];
	int najur=0;
	for(int i=0;i<V.size();i++){
		if(V[i].czyGru()) ur10++;
		if(V[i].czyK()) ilek++;
		t[((int)V[0].p-'0')*10 + (int)V[1].p-'0']++;
	}
	for(int i=1;i<12;i++) if(t[najur] < t[i]) najur=i;

	cout<<"a: "<<ur10<<endl;
	cout<<"b: "<<ilek<<endl;
	cout<<"c: "<<najur<<endl;

}
