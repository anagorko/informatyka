#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

vector <int> v;

void zamiana(int x, int y){
	int p, q;
	p = v[x];
	q = v[y];
	v[x] = q;
	v[y] = p;
}

int minimalna(int a, int b)
{
	int min = v[a];
	int miejsce = a;
	for(int i = a; i <= b; i++)
	{
		if(v[i] < min) {
			min = v[i];
			miejsce = i;
		}	
	}
	return miejsce;
}

void sort()
{
	for(int i = 0; i < v.size(); i++)
	{
		int min = minimalna(i, v.size() - 1);
		zamiana(i, min);
	}
}

int main()
{
	int a;
	int n;
	while(cin >> n)
	{
		v.push_back(n);
	}

	/*for(int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;*/
	
	sort();
		
	/*for(int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;*/
	
	ofstream plik;
	plik.open("posortowane.txt", ios::ate);
	plik << "przez wybór - ";
	for(int i = 0; i < v.size(); i++)
	{
		plik << v[i] << " ";
	}
	plik << endl;	
	plik.close();

}
