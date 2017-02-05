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

void sort()
{
	for(int j = 0; j < v.size(); j++)
		{
			for(int i = 0; i < v.size() - j - 1; i++)
			{
				if(v[i] > v[i + 1]) {
					zamiana(i,i + 1);
				}
			}
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
	
	//write("posortowane.txt");
	/*for(int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;*/
	
	ofstream plik;
	plik.open("posortowane.txt", ios::trunc);
	plik << "babelkowe - ";
	for(int i = 0; i < v.size(); i++)
	{
		plik << v[i] << " ";
	}
	plik << endl;	
	plik.close();

}
