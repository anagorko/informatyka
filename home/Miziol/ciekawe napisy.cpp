#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;

class Napis
{
    string n;

friend istream& operator>>(istream& is, Napis &n);

friend ostream& operator<<(ostream& os, const Napis &n);

public:
    Napis()
    {

    };    
    Napis(string _n)
    {
    	n = _n;
    };

    void setNapis(string _n)
    {
        n = _n;
    };

    string getNapis() const
    {
        return n;
    }

    bool operator<(const Napis& rhs) const
    {
        if(n < rhs.n) return true;
        else return false;
    }

    bool operator==(const Napis& rhs) const
    {
        if(n == rhs.n) return true;
        else return false;      
    }    

    bool czyPierwszy() const
    {
    	 int s = 0;
    	 for(auto v: n)
    	 {
    	 	s += (int)v;
    	 }

    	 for (int i = 2; i <= sqrt(s); i++)
    	 {
    	 	if(s % i == 0) return false;
    	 }
    	 return true;
    }  

    bool czyRosnacy() const
    {
    	for(int i = 1; i < n.size(); i++)
    	{
    		if( n[i] < n[i-1]) return false; 
    	}
    	return true; 
    }
};

istream& operator>>(istream& is, Napis &n)
{
	is >> n.n;
};
ostream& operator<<(ostream& os, const Napis &n)
{
	os << n.n;
};

int main()
{
    ifstream napisy;

    napisy.exceptions(ios::failbit | ios::badbit);
    napisy.open("NAPIS.TXT");    

    vector<Napis> t;

    for (int i = 0; i < 1000; i++) {
        Napis n;
        napisy >> n;
        t.push_back(n);
    }

    napisy.close();

    sort(t.begin(), t.end());

    bool wlasnie_byl = false;

    cout << "Duplikaty:";

    for (vector<Napis>::iterator i = t.begin(); i < t.end(); i++) {
        if (i + 1 < t.end() && *i == *(i+1)) {
            if (!wlasnie_byl) {
                cout << " " << *i; 
            } else {
                wlasnie_byl = true;
            }
        } else {
            wlasnie_byl = false;
        }
    }
    cout << endl;

    int lp = 0;
    for (const Napis& n: t) {
        if (n.czyPierwszy()) lp++;
    }

    cout << endl << "Liczba napisów pierwszych: " << lp << endl << endl;

    cout << "Napisy rosnące:";

    for (const Napis& n: t) {
        if (n.czyRosnacy()) { cout << " " << n; }
    }
    cout << endl << endl;

    return 0;
}