#include <set>
#include <iostream>
using namespace std;

int main()
{
    set<int> s;
    for (int i = 0; i < 10; i++)
    {
        s.insert(i);
    }
    if (s.find(1) != s.end())
    {
        cout << "Found" << endl;
    }
    int idx = 10;
    for (auto it = s.begin(); it != s.end(); it++)
    {
        if (s.find(1) != s.end())
        {
            idx = *it;
            cout << "Thu tu cua 1 la: " << idx << endl;
            break;
        }
    }
    cout << "Thu tu cua 1 la: " << *s.find(1) << endl;

    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }

    cout << endl;
    s.erase(3);
    for (int x: s)
    {
        cout << x << " ";
    }
    return 0;
}