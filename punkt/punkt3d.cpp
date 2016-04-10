#include<iostream>
#include<math.h>
using namespace std;

class Point
{
public:
    Point() {}
    Point(double _x, double _y, double _z)
    {
        // ...
    }

    ~Point() {}

    void setX(double _x) { }  // ...
    void setY(double _y) { }  // ...
    void setZ(double _z) { }  // ...
    
    double getX() { }  // ...
    double getY() { }  // ...
    double getZ() { }  // ...
    
    double distanceTo(Point p) {
        // ...
    }
    
    friend istream& operator>>(istream&, Point&);
};

ostream& operator<<(ostream &o, Point p)
{
    // ...
    
    return o;
}

istream& operator>>(istream &i, Point &p)
{
    // ...
        
    return i;
}


double area(Point a, Point b, Point c)
{
    double ab = a.distanceTo(b);
    double bc = b.distanceTo(c);
    double ac = a.distanceTo(c);
    
    double p = (ab + bc + ac) / 2.0;
    
    return sqrt(p * (p - ab) * (p - ac) * (p - bc));
}

int main()
{
    Point p;
    Point q;
    Point r;

    cout << "Podaj wspolrzedne punktu p: ";
    cin >> p;
    cout << "Podaj wspolrzedne punktu q: ";
    cin >> q;
    cout << "Podaj wspolrzedne punktu r: ";
    cin >> r;

    cout << "Punkty: " << p << " " << q << " " << r << endl;
    cout << "Pole: " << area(p,q,r) << endl;

    return 0;
}
