#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;

bool pierwszosc(int z)
{
    int t[z+1];
    for(int i = 2; i <= z; i++)
    {
        t[i] = true;
    }
    t[0] = -1;
    t[1] = -1;
    for(int i = 2; i <= z; i++)
    {
        if(t[i] == true)
        {
            for(int j = 2; j <= z/i; j++)
            {
                t[i*j] = false;
            }
        }
    }
    if (t[z] == true) return true;
    else return false;
}

class Napis
{
    string n;

public:
    Napis()
	{

	}
    Napis(string _n)
    {
        _n = n;
    }

    void setNapis(string _n)
    {
        n = _n;
    }
    string getNapis() const
    {
        return n;
    }

    bool operator<(const Napis& rhs) const
    {
        if(getNapis() < rhs.getNapis())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator==(const Napis& rhs) const
    {
        if(getNapis() == rhs.getNapis())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool czyPierwszy() const
    {
        int x = 0;
        int q = n.length();
        for(int i = 0; i < q; i++)
        {
            int y = (int) n[i];
            //cout<<"niby ascii"<< y << endl;
            x = x + y;
        }
        //cout<<x<<endl;
        if(pierwszosc(x) == true)
        {
            return true;
        }
        else return false;
    }
    bool czyRosnacy() const
    {
        int q = n.length();
        int z = 0;
        for(int i = 0; i < q; i++)
        {
            int a = (int) n[i];
            //cout<<"a = "<<a<<endl;
            if(a < z) return false;
            z = a;
        }
        //cout<<z<<endl;
        return true;
    }
};


istream& operator>>(istream& is, Napis &n)
{
    string x;
    is>>x;
    n.setNapis(x);
}
ostream& operator<<(ostream& os, const Napis &n)
{
    return os << n.getNapis();
}

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
    cout << "Napisy rosn¹ce:";
    for (const Napis& n: t) {
        if (n.czyRosnacy()) { cout << " " << n; }
    }
    cout << endl << endl;
    return 0;

}
