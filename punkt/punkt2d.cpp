#include<iostream>
#include<math.h>
using namespace std;

class Point
{
    double x, y;

public:
    Point() {}
    Point(double _x, double _y)
    {
        x = _x;
        y = _y;
    }

    ~Point() {}

    void setX(double _x) { x = _x; }
    void setY(double _y) { y = _y; }

    double getX() { return x; }
    double getY() { return y; }

    friend istream& operator>>(istream&, Point&);
};

ostream& operator<<(ostream &o, Point p)
{
    o << "(" << p.getX() << "," << p.getY() << ")";

    return o;
}

istream& operator>>(istream &i, Point &p)
{
    i >> p.x;
    i >> p.y;

    return i;
}

double area_under(Point a, Point b)
{
    return (b.getX() - a.getX()) * (a.getY() + b.getY()) / 2.0;
}

double area(Point a, Point b, Point c)
{
    return fabs(area_under(a,b) + area_under(b,c) + area_under(c,a));
}

int main()
{
    Point p;
    Point q(2.0, 2.0);
    Point r(0.0, 3.0);

    cout << "Podaj wspolrzedne punktu p: ";
    cin >> p;

    cout << "Punkty: " << p << " " << q << " " << r << endl;
    cout << "Pole: " << area(p,q,r) << endl;

    return 0;
}
