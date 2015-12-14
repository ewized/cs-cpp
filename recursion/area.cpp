/*
    10.9
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct point {
    float x;
    float y;
    inline point(float _x, float _y) {
        x = _x;
        y = _y;
    };
    inline void print() {
        cout << x << "," << y << endl;
    };
};

float area(vector<point> points) {
    if (points.size() < 3) {
        return 0;
    }
    point p1 = points[0];
    // p1.print();
    point p2 = points[1];
    // p2.print();
    point p3 = points[2];
    // p3.print();
    float _area = (p1.x * p2.y + p2.x * p3.y + p3.x * p1.y - p1.y * p2.x - p2.y * p3.x - p3.y * p1.x) / 2;
    points.erase(points.begin());
    return (_area < 0 ? -_area : _area) + area(points);
}

int main() {
    vector<point> points = {
        point(5,3),
        point(2,5),
        point(1,1),
        point(9,8),
        point(7,9),
        point(3,7),
    };
    cout << "area: " << area(points) << endl;
    return 0;
}
