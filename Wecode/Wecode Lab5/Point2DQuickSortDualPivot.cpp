#include <iostream>
#include <algorithm>
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

void SapXepNhanhDualPivot(vector < Point > & a, int l, int r) {
    if (l >= r) return;
    if (a[l].getX() > a[r].getX() || (a[l].getX() == a[r].getX() && a[l].getY() < a[r].getY())) {
        swap(a[l], a[r]);
    }
    int p = a[l].getX(), q = a[r].getX();
    int i = l + 1, j = r - 1, k = l + 1;
    while (k <= j) {
        if (a[k].getX() < p || (a[k].getX() == p && a[k].getY() >= a[l].getY())) {
            swap(a[k], a[i]);
            i++;
        } else if ((a[k].getX() >= q || (a[k].getX() == q && a[k].getY() <= a[r].getY())) && k < j) {
            while ((a[j].getX() > q || (a[j].getX() == q && a[j].getY() < a[r].getY())) && k < j) j--;
            swap(a[k], a[j]);
            j--;
            if (a[k].getX() < p || (a[k].getX() == p && a[k].getY() >= a[l].getY())) {
                swap(a[k], a[i]);
                i++;
            }
        }
        k++;
    }
    i--;
    j++;
    swap(a[l], a[i]);
    swap(a[r], a[j]);
    SapXepNhanhDualPivot(a, l, i - 1);
    if (p != q) SapXepNhanhDualPivot(a, i + 1, j - 1);
    SapXepNhanhDualPivot(a, j + 1, r);
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
    SapXepNhanhDualPivot(points, 0, n - 1);
    for (const auto & p: points) {
        p.display();
    }
    return 0;
}