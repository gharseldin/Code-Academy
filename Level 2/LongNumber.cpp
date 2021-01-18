#include <iostream>

using namespace std;

int main()
{
    int n, *mappings;
    char *digits;
    cin >> n;
    digits = new char[n];
    for (int i = 0; i < n; i++)
    {
        cin >> digits[i];
    }
    mappings = new int[10];
    for (int i = 1; i < 10; i++)
    {
        cin >> mappings[i];
    }
    int i = 0;
    // first contigeous set of numbers that are bigger than mappings
    while (i < n && digits[i] - '0' >= mappings[digits[i] - '0'])
    {
        cout << digits[i++];
    }
    // first contigeous set of numbers that are smaller than mappings
    while (i < n && digits[i] - '0' <= mappings[digits[i] - '0'])
    {
        cout << mappings[digits[i] - '0'];
        i++;
    }
    // remaining digits
    while (i < n)
        cout << digits[i++];
    cout << endl;
}
