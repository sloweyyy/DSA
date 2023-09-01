#include <iostream>
#include <cstring>

using namespace std;

int main() {
    string Sb, Se;
    cin >> Sb >> Se;
    int lenSb = Sb.length();
    int lenSe = Se.length();
    int lenOverlap = 0;
    for (int i = 1; i <= lenSb && i <= lenSe; i++) {
        if (Sb.substr(lenSb - i) == Se.substr(0, i)) {
            lenOverlap = i;
        }
    }

    int lenS = lenSb + lenSe - lenOverlap;
    string S = Sb + Se.substr(lenOverlap);
    cout << lenS << endl << S << endl;

    return 0;
}