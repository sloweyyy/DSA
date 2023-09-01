#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Point {
    int x, y;

    void display() const {
        printf("%d %d\n", x, y);
    }
};

void sapxepchen(vector<Point>& a, int n) {
    for (int i = 1; i < n; i++) {
        Point x = a[i];
        int j = i - 1;
        while (j >= 0 && (a[j].x > x.x || (a[j].x == x.x && a[j].y < x.y))) {
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
    scanf("%d", &n);

    vector<Point> points(n);
    for (auto& p : points) {
        scanf("%d %d", &p.x, &p.y);
    }

    sapxepchen(points, n);

    for (const auto& p : points) {
        p.display();
    }

    return 0;
}
