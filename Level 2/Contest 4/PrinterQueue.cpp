// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3252

//#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

int findTime(int n, int position);
int findHeighest(int *priorities);

int main()
{
    int cases, n, position;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        cin >> n >> position;
        cout << findTime(n, position) << endl;
    }
}

int findTime(int n, int position)
{
    int *priorities = new int[10];
    for (int i = 1; i < 10; i++)
        priorities[i] = 0;
    queue<pair<int, int> > q;
    int item;
    for (int i = 0; i < n; i++)
    {
        cin >> item;
        priorities[item]++;
        if (i == position)
            q.push(pair<int, int>(item, 1));
        else
            q.push(pair<int, int>(item, 0));
    }
    int counter = 1;
    int hieghest = findHeighest(priorities);
    while (q.front().second != 1 || q.front().first != hieghest)
    {
        if (q.front().first != hieghest)
            q.push(q.front());
        else
        {
            priorities[hieghest]--;
            if (priorities[hieghest] == 0)
                hieghest = findHeighest(priorities);
            counter++;
        }
        q.pop();
    }
    return counter;
}

int findHeighest(int *priorities)
{
    for (int i = 9; i >= 1; i--)
    {
        if (priorities[i] != 0)
            return i;
    }
    return -1;
}