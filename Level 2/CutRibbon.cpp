
#include <iostream>

using namespace std;

void cutRibbon(int n, int a, int b, int c, int counter, int &total, int *length);
int main()
{
    int n, a, b, c, total = 0, *length;
    cin >> n >> a >> b >> c;
    length = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        length[i] = -1;
    }
    cutRibbon(n, a, b, c, 0, total, length);
    cout << total << endl;
}

void cutRibbon(int n, int a, int b, int c, int counter, int &total, int *length)
{
    if (n >= 0 && length[n] < counter)
    {
        length[n] = counter;
        if (n == 0)
        {
            if (counter > total)
                total = counter;
        }
        else
        {
            cutRibbon(n - a, a, b, c, counter + 1, total, length);
            cutRibbon(n - b, a, b, c, counter + 1, total, length);
            cutRibbon(n - c, a, b, c, counter + 1, total, length);
        }
    }
}
