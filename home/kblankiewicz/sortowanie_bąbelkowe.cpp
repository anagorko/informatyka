#include<iostream>
#include<vector>
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
	for(int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	//cout<< v[0] << " " << v[1] << endl;	
	//zamiana(0,1);
	//cout<< v[0] << " " << v[1] << endl;
	sort();
	for(int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}
