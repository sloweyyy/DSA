#include <iostream>
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

void swap(Point &a, Point &b) {
    Point temp = a;
    a = b;
    b = temp;
}

void heapify(vector<Point> &a, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && (a[left].getX() < a[largest].getX() || (a[left].getX() == a[largest].getX() && a[left].getY() > a[largest].getY()))) {
        largest = left;
    }
    if (right < n && (a[right].getX() < a[largest].getX() || (a[right].getX() == a[largest].getX() && a[right].getY() > a[largest].getY()))) {
        largest = right;
    }
    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void SapXepHeap(vector<Point> &a, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<Point> points(n);
    for (auto & p: points) {
        int x, y;
        cin >> x >> y;
        p = Point(x, y);
    }
    SapXepHeap(points, n);
    for (int i = n-1; i >= 0; i--) {
        points[i].display();
    }
    return 0;
}
