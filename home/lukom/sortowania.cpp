#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
void wypisz(vector <int> v){
        for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
        cout<<"\n";
}
vector <int> bouble_sort(vector <int> v){
	bool posortowany = false;
	while(!posortowany){
		posortowany = true;
		for(int i=1;i<v.size();i++){
			if(v[i] < v[i-1]){
				int l = v[i];
				v[i] = v[i-1];
				v[i-1] = l;
				posortowany = false;
			}
		}
	}
	return v;
}
vector <int> selection_sort(vector <int> v){
	vector <int> w;
	while(v.size() != 0){
		int min = 0;
		for(int i=1;i<v.size();i++){
			if(v[i] < v[min]) min = i;
		}
		w.push_back(v[min]);
		v.erase(v.begin() + min);
	}
	return w;
}
int binary_search( vector <int> &v, int a, int b, int liczba){
	int pocz = (a + b)/2;
	cout<<"a,b: "<<a<<" "<<b<<endl;
	if(b == -1) return 0;
	if(a == b){
		if(v[a] < liczba) return a+1;
		else return a;
	}
	if( b - a == 1){
		if(v[b] < liczba) return b+1;
		else if(v[a] < liczba) return b;
		else return a;
	}
	else if(v[pocz] > liczba) return binary_search(v, a, pocz-1, liczba);
	else if(v[pocz] < liczba) return binary_search(v, pocz+1, b, liczba);
	else if(v[pocz] == liczba) return pocz;
}
vector <int> insertion_sort(vector <int> v){
	vector <int> w;
	for(int i=0;i<v.size();i++){
		int m = binary_search(w, 0, w.size()-1,v[i]);
		if(w.size()>=m) w.insert(w.begin() + m,v[i]);
		else w.push_back(v[i]);
		wypisz(w);
		cout<<endl;
	}
	return w;
}
vector <int> compile( vector <int> v1, vector <int> v2){
	int p1 = 0;
	int p2 = 0;
	vector <int> w;
	while(p1 < v1.size() || p2 < v2.size() ){
		if(p1 < v1.size() && p2 < v2.size() ){
			if(v1[p1] > v2[p2]){
				w.push_back(v2[p2]);
				p2++;
			}else{
				w.push_back(v1[p1]);
				p1++;
			}
		}else if(p1 < v1.size()){
			w.push_back(v1[p1]);
			p1++;
		}else{
			w.push_back(v2[p2]);
			p2++;
		}
	}
	return w;
}
vector <int> quick_sort(vector <int> v){
		if(v.size() == 1) return v;

		int half = v.size()/2;
		vector <int> w1,w2;
		w1 = v;
		w2 = v;

		w1.erase( w1.begin() + half, w1.end());
		w2.erase( w2.begin(), w2.begin() + half );

		w1 = quick_sort(w1);
		w2 = quick_sort(w2);

		return compile(w1, w2);
}
//zwraca ile razy wystepuje dana liczba w ciagu
int  bucket_sort(vector <int> v, int l){
	int ile = 0;
	for(int i=0;i<v.size();i++) if(v[i] == l) ile++;
	return ile;
}
int main(){
	vector <int> v,v1;
	int l;
	while(cin>>l) v.push_back(l);
	wypisz(quick_sort(v));
}
