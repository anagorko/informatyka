#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class Napis
{
    string n;

public:
    Napis(){};    
    Napis(string _n);//done

    void setNapis(string _n);//done
    string getNapis() const;//done    
    bool operator<(const Napis& rhs) const;//done
    bool operator==(const Napis& rhs) const;//done

    bool czyPierwszy() const;//done
    bool czyRosnacy() const;//done
};

istream& operator>>(istream& is, Napis &n);//done
ostream& operator<<(ostream& os, const Napis &n);//done


istream& operator>>(istream& is, Napis &n){
    string s;
    is >> s;
    n.setNapis(s);
}
ostream& operator<<(ostream& os, const Napis &n){
    os << n.getNapis();
}

Napis::Napis(string _n){
    setNapis(_n);
}

void Napis::setNapis(string _n){
    n=_n;
}

string Napis::getNapis() const{
    return n;
}

bool Napis::operator<(const Napis& rhs) const{
    if(n<rhs.getNapis()) return 1;
    return 0;
}

bool Napis::operator==(const Napis& rhs) const{
    if(n==rhs.getNapis()) return 1;
    return 0;   
}

bool Napis::czyRosnacy() const{//podobno mozna zrobc prosciej
    for(int i=0;i<n.length()-1;i++){
        if((int)n[i]>(int)n[i+1]) return 0;
    }
    return 1;
}

bool Napis::czyPierwszy() const{
    int sl=0;
    for(int i=0;i<n.length();i++){
        sl+=(int)n[i];
    }


    for(int i=2;i*i<=sl;i++){
        if((sl%i)==0) return false;
    }

    return true;
}

int main()
{
    ifstream napisy;

    napisy.exceptions(ios::failbit | ios::badbit);
    napisy.open("dane_PR/NAPIS.TXT");    

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
