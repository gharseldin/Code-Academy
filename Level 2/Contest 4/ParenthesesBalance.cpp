// https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=614

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isValid(string s);
bool isOpenningBracket(char c);
bool isClosingBracket(char c);
bool isMatchingTop(char closing, stack<char> brackets);
bool isMatchingBrackets(char open, char closing);

int main()
{
    int n;
    string A;
    cin >> n;
    cin.ignore(); //to flush the newline character
    for (int i = 0; i < n; i++)
    {
        getline(cin, A);
        cout << (isValid(A) ? "Yes" : "No") << endl;
    }
}

bool isValid(string s)
{
    stack<char> brackets;
    for (int i = 0; i < int(s.size()); i++)
    {
        if (isOpenningBracket(s[i]))
        {
            brackets.push(s[i]);
        }
        else if (isClosingBracket(s[i]))
        {
            if (isMatchingTop(s[i], brackets))
                brackets.pop();
            else
                return false;
        }
        else
        {
            // Do nothing since it could be any character
        }
    }
    return brackets.empty();
}

bool isOpenningBracket(char c)
{
    return c == '(' || c == '[';
}

bool isClosingBracket(char c)
{
    return c == ')' || c == ']';
}

bool isMatchingTop(char closing, stack<char> brackets)
{
    if (brackets.empty())
        return false;
    char opening = brackets.top();
    if (isMatchingBrackets(opening, closing))
        return true;
    return false;
}

bool isMatchingBrackets(char open, char closing)
{
    return (open == '(' && closing == ')') || (open == '[' && closing == ']');
}
