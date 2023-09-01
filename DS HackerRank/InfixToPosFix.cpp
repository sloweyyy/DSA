#include <iostream>
#include <stack>
#include <string>

using namespace std;

int precedence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    default:
        return 0;
    }
}

string infixToPostfix(const string &infix)
{
    stack<char> s;
    string postfix;
    for (char c : infix)
    {
        if (isalnum(c))
        {
            postfix += c;
        }
        else if (c == '(')
        {
            s.push(c);
        }
        else if (c == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty())
            {
                s.pop(); // remove '('
            }
        }
        else
        {
            while (!s.empty() && precedence(c) <= precedence(s.top()))
            {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}

float evaluatePostfix(const string &postfix)
{
    stack<float> s;
    for (char c : postfix)
    {
        if (isdigit(c))
        {
            s.push(c - '0');
        }
        else
        {
            float op2 = s.top();
            s.pop();
            float op1 = s.top();
            s.pop();
            switch (c)
            {
            case '+':
                s.push(op1 + op2);
                break;
            case '-':
                s.push(op1 - op2);
                break;
            case '*':
                s.push(op1 * op2);
                break;
            case '/':
                s.push(op1 / op2);
                break;
            case '%':
                s.push(fmod(op1, op2));
                break;
            default:
                return 0; // invalid operator
            }
        }
    }
    return s.top();
}

int main()
{
    string infix, postfix;
    cout << "Enter infix expression: ";
    getline(cin, infix);
    postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;
    float result = evaluatePostfix(postfix);
    cout << "Result: " << result << endl;
    return 0;
}