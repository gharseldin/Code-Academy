#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, *number, stability;
    cin >> n;
    number = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> number[i];
    }
    sort(number, number + n);
    if (n == 2)
        stability = 0;
    else if (n == 3)
        stability = number[2] - number[1] < number[1] - number[0] ? number[2] - number[1] : number[1] - number[0];
    else
    {
        stability = number[n - 1] - number[1] < number[n - 2] - number[0] ? number[n - 1] - number[1] : number[n - 2] - number[0];
    }
    cout << stability << endl;
}
