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

void SapXepChon(vector < Point > & a, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j].getX() < a[minIndex].getX() || (a[j].getX() == a[minIndex].getX() && a[j].getY() > a[minIndex].getY())) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(a[i], a[minIndex]);
        }
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
    SapXepChon(points, n);
    for (const auto & p: points) {
        p.display();
    }
    return 0;
}