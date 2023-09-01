#include <iostream>

#include <vector>

using namespace std;

class Point {
    private: int x,
    y;
    public: Point() {
        x = y = 0;
    }
    Point(int x, int y) {
        this -> x = x;
        this -> y = y;
    }
    int getX() const {
        return x;
    }
    int getY() const {
        return y;
    }
    void display() const {
        cout << x << " " << y << endl;
    }
};

void merge(vector < Point > & a, int l, int m, int r) {
    int i = l, j = m + 1, k = 0;
    vector < Point > tmp(r - l + 1);
    while (i <= m && j <= r) {
        if (a[i].getX() < a[j].getX() || (a[i].getX() == a[j].getX() && a[i].getY() > a[j].getY())) {
            tmp[k++] = a[i++];
        } else {
            tmp[k++] = a[j++];
        }
    }
    while (i <= m) {
        tmp[k++] = a[i++];
    }
    while (j <= r) {
        tmp[k++] = a[j++];
    }
    for (i = l, k = 0; i <= r; i++, k++) {
        a[i] = tmp[k];
    }
}

void sapxepgop(vector < Point > & a, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        sapxepgop(a, l, m);
        sapxepgop(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector < Point > points(n);
    for (auto & p: points) {
        int x, y;
        cin >> x >> y;
        p = Point(x, y);
    }
    sapxepgop(points, 0, n - 1);
    for (const auto & p: points) {
        p.display();
    }
    return 0;
}