#include <iostream>
using namespace std;
class Point {
public:
    Point(int a = 0, int b = 0): x(a), y(b) {}
    Point operator+=(const Point & p);
    Point operator=(const Point & p);
    Point operator*(const Point & p) const;
    friend ostream & operator<<(ostream & os, const Point & p);
private:
    int x;
    int y; 
};

int main() {
    Point a(5,6);
    Point b(1,2);
    a += b;
    cout << a << b;
    Point c = a * b;
    cout << c << endl;
    return 0;
}

Point Point::operator+=(const Point & p) {
    x += p.x;
    y += p.y;
    return *this;
}

Point Point::operator=(const Point & p) {
    x = p.x;
    y = p.y;
    return *this;
}

Point Point::operator*(const Point & p) const {
    Point tmp;
    tmp.x = x * p.x;
    tmp.y = y * p.y;
    return tmp;
}

ostream & operator<<(ostream & os, const Point & p) {
    os << "(" << p.x << ", " << p.y << ")" << endl;
}