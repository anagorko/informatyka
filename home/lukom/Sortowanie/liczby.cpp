#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool operator < ( string s1, string s2 ){
	if(s1.length() == s2.length()){
		return s1 < s2;

	}else{
		if(s1.length() < s2.length() ) return true;
		else return false;
	}
}
int main(){
	vector <string> V;
	string s;
	while(cin >> s) V.push_back(s);
	sort(V.begin(), V.end());
	for(int i=0;i<V.size();i++) cout<<V[i]<<endl;

}
