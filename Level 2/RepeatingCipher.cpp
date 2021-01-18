#include <iostream>

using namespace std;

int main()
{
    string encrypted;
    int n, letter = 0;
    cin >> n >> encrypted;
    int i = 0;
    while (i < n)
    {
        cout << encrypted[i];
        letter++;
        i += letter;
    }
    cout << endl;
}
