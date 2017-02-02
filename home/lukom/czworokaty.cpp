#include<iostream>
#include<fstream>
#include<vector>
#include<math.h>
#include<iomanip>
using namespace std;
class punkt {
	public:
	double x,y;
};
class trojkat {
	public:
	int p[3][2];
	void wypisz() const;
	bool tylko_I_cwiartka() const;
	bool na_prostej() const;
	double obwod() const;
	bool prostokatny() const;
	punkt D() const;
};
punkt trojkat::D() const {
	int abx = p[1][0] - p[0][0];
        int aby = p[1][1] - p[0][1];

        int bcx = p[2][0] - p[1][0];
        int bcy = p[2][1] - p[1][1];

        int acx = p[2][0] - p[0][0];
        int acy = p[2][1] - p[0][1];

	punkt d;
	d.x = p[2][0] + (-abx);
	d.y = p[2][1] + (-aby);
	return d;
}
bool trojkat::prostokatny() const {
	double abx = p[1][0] - p[0][0];
        double aby = p[1][1] - p[0][1];
        double ab2 = abx * abx + aby * aby;

        double bcx = p[2][0] - p[1][0];
        double bcy = p[2][1] - p[1][1];
        double bc2 = bcx * bcx + bcy * bcy;

        double acx = p[2][0] - p[0][0];
        double acy = p[2][1] - p[0][1];
        double ac2 = acx * acx + acy * acy;

	if((ab2 + bc2 == ac2)
	|| (bc2 + ac2 == ab2)
	|| (ac2 + ab2 == bc2)) return true;
	else return false;
}
double trojkat::obwod() const {
	double abx = p[1][0] - p[0][0];
	double aby = p[1][1] - p[0][1];
	double ab = sqrt( abx * abx + aby * aby );

	double bcx = p[2][0] - p[1][0];
	double bcy = p[2][1] - p[1][1];
	double bc = sqrt( bcx * bcx + bcy * bcy );

	double acx = p[2][0] - p[0][0];
	double acy = p[2][1] - p[0][1];
	double ac = sqrt( acx * acx + acy * acy );
	return ab + bc + ac;
}
bool trojkat::na_prostej() const {
	double abx = p[1][0] - p[0][0];
	double aby = p[1][1] - p[0][1];

	double acx = p[2][0] - p[0][0];
	double acy = p[2][1] - p[0][1];

	if( (acx < 0 && abx > 0) || (acx > 0 && abx < 0)){
		acx*=-1;
		acy*=-1;
	}

	if(abx == 0 || aby == 0){
		if(abx == 0 && acx == 0) return true;
		if(aby == 0 && acy == 0) return true;
		return false;
	}else if(acx / abx == acy / aby ) return true;
	else return false;
}
bool trojkat::tylko_I_cwiartka() const {
	for(int i=0;i<3;i++) if(p[i][0] <= 0 || p[i][1] <= 0) return false;
	return true;
}
void trojkat::wypisz() const {
	for(int i=0;i<3;i++){
		cout<<p[i][0]<<" "<<p[i][1]<<"\n";
	}
	cout<<"\n";
}
bool lezy_na_prostej(punkt p){
	if(p.x == p.y) return true;
	else return false;
}
vector <trojkat> W, Tr;
void wczytanie(){
	fstream plik, plikTr;
	plik.open("../../zbior_zadan/81/wspolrzedne.txt");
	plikTr.open("../../zbior_zadan/81/wspolrzedneTR.txt");
	for(int i=0;i<100;i++){
		trojkat tr;
		trojkat tr2;
		for(int j=0;j<3;j++){
			plik >> tr.p[j][0];
			plik >> tr.p[j][1];

			plikTr >> tr2.p[j][0];
			plikTr >> tr2.p[j][1];
		}
		W.push_back(tr);
		Tr.push_back(tr2);
	}
	plik.close();
}
void pyt1(){
	int ile=0;
	for(int i=0;i<W.size();i++){
		if(W[i].tylko_I_cwiartka()) ile++;
	}
	cout<<ile<<endl;
}
void pyt2(){
	int ile=0;
	for(int i=0;i<100;i++){
		if(W[i].na_prostej()) ile++;
	}
	cout<<ile<<endl;
}
void pyt3(){
	double obw_max = 0;
	int nr = 0;
	for(int i=0;i<100;i++){
		double obw = Tr[i].obwod();
		if(obw > obw_max){
			obw_max = obw;
			nr = i;
		}
	}
	cout<<"najwiekszy obwod: "<<fixed<<setprecision(2)<<obw_max<<"\n";
	cout<<"ma go trojkat w rzedzie "<<nr+1<<"\n";
}
void pyt4(){
	int ile=0;
	for(int i=0;i<100;i++){
		if(Tr[i].prostokatny()) ile++;
	}
	cout<<ile<<endl;
}
void pyt5(){
	for(int i=0;i<100;i++){
		punkt p = Tr[i].D();
		if(!lezy_na_prostej(p)) continue;
		for(int j=0;j<3;j++) cout<<Tr[i].p[j][0]<<" "<<Tr[i].p[j][1]<<"\n";
		cout<<p.x<<" "<<p.y<<"\n\n";
        }
}
int main(){
	wczytanie();
//	pyt1();
//	pyt2();
//	pyt3();
//	pyt4();
//	pyt5();
}
