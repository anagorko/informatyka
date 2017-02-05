#include<vector>
#include<iostream>
using namespace std;

vector <int> v;

void scal(vector <int> & k, vector <int> & l, vector <int> & m)
{
	int _k = 0;
	int _l = 0;	
	m.clear();
	while(_k < k.size() || _l < l.size())
	{
		if(_k > k.size() - 1){
			m.push_back(l[_l]);
			_l += 1;	
		}
		else if(_l > l.size() - 1){
			m.push_back(k[_k]);
			_k += 1;
		}
		else if(k[_k] >= l[_l]){
			m.push_back(l[_l]);
			_l += 1;
		}	
		else{
			m.push_back(k[_k]);
			_k += 1;
		}
	}
	/*cout << "scalony  ";
	for(int i = 0; i < m.size(); i++)
	{
		cout << m[i] << " "; 
	}
	cout << endl;*/
}

void podziel(vector <int> & x, vector <int> & p, vector <int> & q)
{
	p.clear();
	q.clear();
	int a = x.size() / 2;
	for(int i = 0; i < a; i++)
	{
		p.push_back(x[i]);
	}
	for(int i = a; i < x.size(); i++)
	{
		q.push_back(x[i]);
	}
	/*
	cout << " rozmiar = " << v.size() << " a = " << a << endl;
	for(int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl; 
	}
	for(int i = 0; i < a + v.size()%2; i++)
	{
		cout << p[i] << " " << q[i] << endl;
	}*/
}

void sort(vector <int> & u)
{
	if(u.size() == 1){
		return;
	}
	vector <int> s, t;
	podziel(u, s, t);
	/*cout << "podzielony  ";
	for(int i = 0; i < s.size(); i++)
	{
		cout << s[i] << " "; 
	}
	cout << "  ";
	for(int i = 0; i < t.size(); i++)
	{
		cout << t[i] << " "; 
	}
	cout << endl;*/
	sort(s);
	sort(t);
	scal(s, t, u);

}

int main()
{
	int n;
	while(cin >> n)
	{
		v.push_back(n);
	}

	sort(v);
		
	cout << "koniec  ";
	for(int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " "; 
	}

}
