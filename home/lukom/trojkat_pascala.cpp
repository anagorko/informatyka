#include<iostream>
using namespace std;
class trojkat{
	public:
	int t[30][30];
	void fill();
	void push();
	int get(int x, int y)const;
};
int trojkat::get(int x, int y)const{
	return t[x-1][y-1];
}
void trojkat::fill(){
	for(int i=0;i<30;i++)	for(int a=0;a<30;a++) t[i][a]=0;
	t[0][0]=1;
	for(int i=1;i<30;i++){
		t[i][0]=1;
		for(int a=1;a<30;a++){
			t[i][a] = t[i-1][a-1] + t[i-1][a];
		}
	} 
}
void trojkat::push(){
	for(int i=0;i<30;i++){
		for(int a=0;a<i+1;a++){
			cout<<t[i][a]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n";
}
int main(){
	trojkat T;
	T.fill();
	T.push();
	int najw10 = 0;
	int najw20 = 0;
	int najw30 = 0;
	for(int i=0;i<30;i++) if(najw10 < T.get(10,i)) najw10 = T.get(10,i);
	for(int i=0;i<30;i++) if(najw20 < T.get(10,i)) najw20 = T.get(20,i);  
        for(int i=0;i<30;i++) if(najw30 < T.get(10,i)) najw30 = T.get(30,i); 
	cout<<"najw10 = "<<najw10<<endl;
        cout<<"najw20 = "<<najw20<<endl;
        cout<<"najw30 = "<<najw30<<endl;

}
