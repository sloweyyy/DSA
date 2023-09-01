#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Point {
private:
    int x, y;
public:
    Point() {
        x = y = 0;
    }
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
    int getX() const {
        return x;
    }
    int getY() const {
        return y;
    }
    void display() const {
        cout << x << " " << y <<endl;
    }
};

void sapxepchen(vector<Point>& a, int n) {
    for (int i = 1; i < n; i++) {
        Point x = a[i];
        int j = i - 1;
        while (j >= 0 && (a[j].getX() > x.getX() || (a[j].getX() == x.getX() && a[j].getY() < x.getY()))) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<Point> points(n);
    for (auto& p : points) {
        long long x, y;
        cin >> x >> y;
        p = Point(x, y);
    }
    sapxepchen(points, n);
    for (const auto& p : points) {
        p.display();
    }
    return 0;
}