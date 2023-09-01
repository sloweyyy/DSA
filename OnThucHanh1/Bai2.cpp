#include <iostream>
#include <stack>
#include <string>
using namespace std;

int doUuTien(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

int tinhToan(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    }
    return 0;
}

int tinhGiaTriBieuThuc(string tokens)
{
    int i;

    stack<int> giaTri;

    stack<char> toanTu;

    for (i = 0; i < tokens.length(); i++)
    {

        if (tokens[i] == ' ')
            continue;

        else if (tokens[i] == '(')
        {
            toanTu.push(tokens[i]);
        }

        else if (isdigit(tokens[i]))
        {
            int val = 0;

            while (i < tokens.length() &&
                   isdigit(tokens[i]))
            {
                val = (val * 10) + (tokens[i] - '0');
                i++;
            }

            giaTri.push(val);

            i--;
        }

        else if (tokens[i] == ')')
        {
            while (!toanTu.empty() && toanTu.top() != '(')
            {
                int val2 = giaTri.top();
                giaTri.pop();

                int val1 = giaTri.top();
                giaTri.pop();

                char op = toanTu.top();
                toanTu.pop();

                giaTri.push(tinhToan(val1, val2, op));
            }

            if (!toanTu.empty())
                toanTu.pop();
        }

        else
        {
            while (!toanTu.empty() && doUuTien(toanTu.top()) >= doUuTien(tokens[i]))
            {
                int val2 = giaTri.top();
                giaTri.pop();

                int val1 = giaTri.top();
                giaTri.pop();

                char op = toanTu.top();
                toanTu.pop();

                giaTri.push(tinhToan(val1, val2, op));
            }

            toanTu.push(tokens[i]);
        }
    }

    while (!toanTu.empty())
    {
        int val2 = giaTri.top();
        giaTri.pop();

        int val1 = giaTri.top();
        giaTri.pop();

        char op = toanTu.top();
        toanTu.pop();

        giaTri.push(tinhToan(val1, val2, op));
    }

    return giaTri.top();
}

int main()
{
    string bieuThuc;
    cout << "Nhap bieu thuc: ";
    getline(cin, bieuThuc);

    float ketQua = tinhGiaTriBieuThuc(bieuThuc);
    cout << "Ket qua: " << ketQua << endl;

    return 0;
}
