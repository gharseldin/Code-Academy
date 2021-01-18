#include <iostream>

using namespace std;

void reverse(string &s, int start, int end);
int main()
{
    int n;
    string encrypted;
    cin >> n >> encrypted;
    for (int i = 2; i <= n; i++)
    {
        if (n % i == 0)
        {
            reverse(encrypted, 0, i);
        }
    }
    cout << encrypted << endl;
}

void reverse(string &s, int start, int end)
{
    for (int i = start; i < start + (end - start) / 2; i++)
    {
        char temp = s[i];
        s[i] = s[end - 1 - i];
        s[end - 1 - i] = temp;
    }
}
