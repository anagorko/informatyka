#include<iostream>
#include<vector>
using namespace std;
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
	if(a == b) return//zle 
	if(v[pocz] > liczba) return binary_search(*v, a, pocz, liczba);
	else if(v[pocz] < liczba]) return binary_search(*v, pocz, b, liczba);
	
	}
}
vector <int> insertion_sort(vector <int> v){
	vector <int> w;
	for(int i=0;i<v.size();i++){
		
	}

}
void wypisz(vector <int> v){
	for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
	cout<<"\n";
}
int main(){
	vector <int> v;
	int l;
	while(cin>>l) v.push_back(l);

	wypisz(selection_sort(v));
}
