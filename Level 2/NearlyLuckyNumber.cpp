#include <iostream>
using namespace std;

int main()
{
    long long n, temp;
    int count = 0;
    cin >> n;
    while (n > 0)
    {
        temp = n % 10;
        if (temp == 4 || temp == 7)
            count++;
        n /= 10;
    }
    cout << ((count == 4 || count == 7) ? "YES" : "NO") << endl;
}
