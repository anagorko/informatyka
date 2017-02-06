#include<vector>
#include<iostream>
using namespace std;

vector <int> v;

void join(vector <int> & p, vector <int> & q, int z, vector <int> & r)
{
	r.clear();
	for(int i = 0; i < p.size(); i++)
	{
		r.push_back(p[i]);
	}
	r.push_back(z);
	for(int i = 0; i < q.size(); i++)
	{
		r.push_back(q[i]);
	}
}

void sort(vector <int> & s)
{
	if(s.size() <= 1){
		return;s
	}
	int a = s[0];
	vector <int> m, w;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] < a){
			m.push_back(s[i]);
		}
		if(s[i] > a){
			w.push_back(s[i]);
		}
	}
	sort(m);
	sort(w);
	join(m, w, a, s);
}

int main()
{
	int n;
	while(cin >> n)
	{
		v.push_back(n);
	}
	
	sort(v);

	for(int i = 0; i < v.size(); i++)
	{
		cout<< v[i] << " ";
	}
	cout << endl;

} 
