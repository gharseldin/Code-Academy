#include <iostream>

using namespace std;

int main()
{
    int n, k, *problem;
    cin >> n >> k;
    problem = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> problem[i];
    }
    int start = 0, end = n - 1, solved = 0;
    while (start <= end)
    {
        if (problem[start] <= k)
        {
            start++;
            solved++;
        }
        else if (problem[end] <= k)
        {
            end--;
            solved++;
        }
        else
        {
            break;
        }
    }
    cout << solved << endl;
}
