#include<iostream>
#include<vector>
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

void sort_b()
{
	for(int j = 0; j < gotowe.size(); j++)
		{
			for(int i = 0; i < gotowe.size() - j - 1; i++)
			{
				if(gotowe[i] > gotowe[i + 1]) {
					zamiana(i,i + 1);
				}
			}
		}
		
}

void sort()
{
	for(int i = 0; i < v.size(); i++)
	{ 
		gotowe.push_back(v[v.size() - 1 - i]);
		for(int j = gotowe.size() - 1; j >= 0; j--)
		{
			if(gotowe[j] > gotowe[j - 1]){
				break;
			}
			else{
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

	sort();

	for(int i = 0; i < gotowe.size(); i++)
	{
		cout << gotowe[i] << " ";
	}
	cout << endl;

}
