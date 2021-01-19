#include <iostream>
using namespace std;

bool allDigitsDistinct(int num);
int main()
{
    int l, r;
    cin >> l >> r;
    for (int i = l; i <= r; i++)
    {
        if (allDigitsDistinct(i))
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
bool allDigitsDistinct(int num)
{
    int *numbers = new int[10];
    for (int i = 0; i < 10; i++)
    {
        numbers[i] = 0;
    }
    while (num > 0)
    {
        if (numbers[num % 10] != 0)
            return false;
        numbers[num % 10]++;
        num /= 10;
    }
    return true;
}
