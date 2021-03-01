// https://codeforces.com/problemset/problem/343/B

//#include <bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<char> cross;
    string wire;
    getline(cin, wire);
    for (int i = 0; i < int(wire.size()); i++)
    {
        if (!cross.empty() && cross.top() == wire[i])
            cross.pop();
        else
            cross.push(wire[i]);
    }
    cout << (cross.empty() ? "Yes" : "No") << endl;
}
