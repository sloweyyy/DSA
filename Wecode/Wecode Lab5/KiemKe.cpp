#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    string codes[n];
    int count = 0;

    for (int i = 0; i < n; i++) {
        string code;
        cin >> code;

        bool found = false;
        for (int j = 0; j < count; j++) {
            if (code == codes[j]) {
                found = true;
                break;
            }
        }

        if (!found) {
            codes[count++] = code;
        }
    }

    cout << count;

    return 0;
}
