#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, a, b, c, d, *coins;
    coins = new int[3];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c >> d;
        coins[0] = a;
        coins[1] = b;
        coins[2] = c;
        sort(coins, coins + 3);
        int diff = 2 * coins[2] - coins[1] - coins[0];
        d -= diff;
        if (d < 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << (d % 3 == 0 ? "YES" : "NO") << endl;
        }
    }
}