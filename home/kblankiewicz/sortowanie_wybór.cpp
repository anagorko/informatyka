#include<iostream>
#include<vector>
#include<random>
using namespace std;

vector <int> v;
vector <int> gotowe;

void zamiana(int x, int y){
	int p, q;
	p = gotowe[x];
	q = gotowe[y];
	gotowe[x] = q;
	gotowe[y] = p;
}

void sort()
{
	for(int i = 0; i < v.size(); i++)
	{ 
		gotowe.push_back(v[v.size() - 1]);
		v.pop();
		for(int j = gotowe.size() - 1; j >= 0; j--)
		{
			if(gotowe[j] < gotowe[j - 1]){
				zamiana(j, j - 1);
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
	for(int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	//cout<< v[0] << " " << v[1] << endl;	

	//cout<< v[0] << " " << v[1] << endl;
	sort();
	for(int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}
