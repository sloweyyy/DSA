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

void SapXepDem(vector < Point > & a, int n, int exp) {
    vector < Point > output(n);
    int count[10] = {
        0
    };

    for (int i = 0; i < n; i++) {
        count[(a[i].getX() / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(a[i].getX() / exp) % 10] - 1] = a[i];
        count[(a[i].getX() / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        a[i] = output[i];
    }
}

void SapXepRadix(vector < Point > & a, int n) {
    int max_x = a[0].getX();
    int max_y = a[0].getY();
    for (int i = 1; i < n; i++) {
        if (a[i].getX() > max_x) {
            max_x = a[i].getX();
        } else if(a[i].getX()==max_x && a[i].getY()>max_y){
            max_y = a[i].getY();
        }
    }

    for (int exp = 1; max_x / exp > 0; exp *= 10) {
        SapXepDem(a, n, exp);
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
    SapXepRadix(points, n);
    for (const auto & p: points) {
        p.display();
    }
    return 0;
}