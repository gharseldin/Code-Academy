#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
    ll q, a, b, k, pos = 0;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> a >> b >> k;
        if (k & 1)
        {
            pos += a * (k / 2 + 1);
        }
        else
        {
            pos += a * (k / 2);
        }
        pos -= b * (k / 2);
        cout << pos << endl;
        pos = 0;
    }
}
