#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct punkt{
	int x;
	int y;
	int wkole;//-1 - w kole, 0 - na okręgu, 1 - poza okregiem;
};
int main(){

	vector<punkt> v;
	int nk=0;

	fstream file;

	file.open("punkty.txt", ios::in);

	if(!file.is_open())cout<<"holyshit\n";
	for(int i = 0; i<10000;i++){
		punkt p;
		file>>p.x;
		file>>p.y;
		if( (p.x - 200) * (p.x - 200) + (p.y - 200) * (p.y - 200) == 200 * 200){
			p.wkole=0;
		}else if( (p.x - 200) * (p.x - 200) + (p.y - 200) * (p.y - 200) < 200 * 200){
			p.wkole=-1;
			nk++;
		}else{
			p.wkole = 1;
		}
		v.push_back(p);
	}
	file.close();

	cout<<"punkty należące do okręgu: \n";
	for(int i=0;i<v.size();i++){
		if(v[i].wkole==0) cout<<v[i].x<<" "<<v[i].y<<endl;
	}
/*
	cout<<"punkty należące do koła: \n";
	for(int i=0;i<v.size();i++){
		if(v[i].wkole==-1) cout<<v[i].x<<" "<<v[i].y<<endl;
	}
*/
	cout<<"nk = "<<nk<<endl;

}