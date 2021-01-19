#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll findMax(ll a, ll b, ll c);
int main()
{
    int q;
    ll *bag = new ll(3);
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> bag[0] >> bag[1] >> bag[2];
        sort(bag, bag + 3);
        ll dist = bag[2];
        dist -= bag[1] - bag[0];
        cout << bag[1] + dist / 2 << endl;
    }
}