#include <iostream>

using namespace std;

int main()
{
    int n, moves = 1;
    cin >> n;
    if (n < 10)
    {
        cout << 9 << endl;
        return 0;
    }
    n++;
    while (n >= 10)
    {
        if (n % 10 == 0)
        {
            n /= 10;
        }
        else
        {
            n++;
            moves++;
        }
    }
    cout << moves + 9 << endl;
}
