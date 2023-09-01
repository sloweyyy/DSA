#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
class Rectangle
{
public:
    double x0, y0, x1, y1;
    double area;

    Rectangle(double _x0, double _y0, double _x1, double _y1)
    {
        x0 = _x0;
        y0 = _y0;
        x1 = _x1;
        y1 = _y1;
        area = (x1 - x0) * (y1 - y0);
    }

    bool operator<(const Rectangle &other) const
    {
        return area > other.area;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<Rectangle> rectangles;

    for (int i = 0; i < n; i++)
    {
        double x0, y0, x1, y1;
        cin >> x0 >> y0 >> x1 >> y1;
        rectangles.push_back(Rectangle(x0, y0, x1, y1));
    }

    sort(rectangles.begin(), rectangles.end());
    for (int i = 0; i < n; i++)
    {
        cout << fixed << setprecision(1) << rectangles[i].x0 << "\t" << rectangles[i].y0 << "\t" << rectangles[i].x1 << "\t" << rectangles[i].y1 << endl;
    }

    return 0;
}
