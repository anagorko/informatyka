#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	vector <int> V;
	int l;
	while (cin >> l ) V.push_back(l);
	sort(V.begin(), V.end());
	for(int i=0;i<V.size();i++) cout<<V[i]<<"\n";
}
