#define GpW 4.5f
#define BpW 3.8f
#define SG 32.0f
#define SB 28.0f
#define SK 16500
#include<iostream>
using namespace std;
int main(){
float G = 500.0f;
float B = 200.0f;
float uG = 0;
float uB = 0;

int odpa=0;
	for(int d=1;d<=9*30+3;d++){//dla pdpkt a trzba dac d<=30
		//cout<<"DZIEŃ "<<d<<endl;
		cout<<" "<<G<<" "<<B<<" pozostalo do ulozenia:"<<SK - (uG + uB)<<endl;
		if(d%7==2 || d%7==3) continue;//sobota niedziela

		if(G >= 20*GpW){
			G -= 20 * GpW;

			uG += 20 * GpW;
		}else{
			G = G - 10 * GpW;
			B = B - 10 * BpW;

			uG += 10 * GpW;
			uB += 10 * BpW;
		}

		if(G < 40){
			G += 3 * SG;
		//	cout<<d<<" ";
		}else if(G >= 40.0f &&  G <= 100.0f){
			G += SG;
		//	cout<<d<<" ";
		}
		if(d%7 == 6 || d%7 == 4){//poniedzialek, sroda
			B += SB;
			odpa++;
		}
	}
	cout<<"\nA: "<<odpa<<endl;
}

