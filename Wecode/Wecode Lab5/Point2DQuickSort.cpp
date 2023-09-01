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

void SapXepNhanh(vector<Point>& a, int l, int r) {
    if (l >= r) return;
    int i = l, j = r;
    Point pivot = a[(l + r) / 2];
    while (i <= j) {
        while (a[i].getX() < pivot.getX() || (a[i].getX() == pivot.getX() && a[i].getY() > pivot.getY())) i++;
        while (a[j].getX() > pivot.getX() || (a[j].getX() == pivot.getX() && a[j].getY() < pivot.getY())) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    SapXepNhanh(a, l, j);
    SapXepNhanh(a, i, r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<Point> points(n);
    for (auto& p : points) {
        int x, y;
        cin >> x >> y;
        p = Point(x, y);
    }
    SapXepNhanh(points, 0, n - 1);
    for (const auto& p : points) {
        p.display();
    }
    return 0;
}
