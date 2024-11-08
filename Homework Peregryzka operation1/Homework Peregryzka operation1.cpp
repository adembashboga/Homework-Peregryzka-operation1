#include<iostream>
#include<time.h>
using namespace std;

class Point {
    int x;
    int y;
public:
    Point() : x(0), y(0) {
        cout << "Construct\n";
    }
    Point(int x1, int y1) : x(x1), y(y1) {
        cout << "Construct by 2 param\n";
    }

    void Output() const {
        cout << "X: " << x << "\tY: " << y << endl;
    }
    Point operator*(int a) const {
        return Point(x * a, y * a);
    }
    Point operator/(int a) const {
        if (a != 0) {
            return Point(x / a, y / a);
        }
        else {
            cout << "Division by zero error!\n";
            return *this;
        }
    }
    Point operator*(const Point& b) const {
        return Point(x * b.x, y * b.y);
    }
    Point operator/(const Point& b) const {
        if (b.x != 0 && b.y != 0) {
            return Point(x / b.x, y / b.y);
        }
        else {
            cout << "Division by zero error!\n";
            return *this;
        }
    }
};

int main() {
    Point a(1, 2);
    Point b(3, 4);

    //Point c = a + b;
    Point c = a.operator+(b);
    c.Output();

    //c = a + 10;
    c = a.operator+(10);
    c.Output();

    Point c = a * 3;
    c.Output();

    c = a / 2;
    c.Output();

    c = a * b;
    c.Output();

    c = a / b;
    c.Output();
}
