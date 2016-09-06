#include<iostream>
#include<vector>
using namespace std;

string alfabet(string s)
{
	string t = s;
	int p, q;

	for(int i = 0; i < s.length();i++)
	{
		for(int j = 0; j < s.length() - 1; j++)
		{
			p = t[j];
			q = t[j + 1];
			if(p > q)
			{
				t[j] = q;
				t[j + 1] = p;
			}
		}
	}
	return t;
}

int main()
{
	/*string v, w;
	cin>>v>>w;
	if(alfabet(v) == alfabet(w)) cout<<"anagramy"<<endl;
	else cout << "niestety nie" <<endl;*/

	vector <string> v;
	string s;

	cout << "podaj wyrazy" << endl;

	while(!cin.eof())
	{
		cin>>s;
		v.push_back(s);
	}

	bool t[v.size() - 1];
	for(int i = 0; i < v.size(); i++)
	{
		t[i] = false;
	}

    cout << endl << "anagramy:" << endl;

	for(int i = 0; i < v.size(); i++)
	{
		if(t[i] == false)
		{
		    cout << v[i] << " ";
			for(int j = 0; j < v.size(); j++)
			{
				if(j != i)
				{
					if(alfabet(v[i]) == alfabet(v[j]))
					{
						cout << v[j] << " ";
						t[j] = true;
					}
				}
			}
            cout << endl;
		}
	}

}
