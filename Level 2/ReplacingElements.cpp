#include <iostream>
#include <algorithm>
using namespace std;

bool FoundElementLargerThanD(int *num, int n, int d);
bool FoundTwoElementsAddToDOrLess(int *num, int n, int d);

int main()
{

    int q, n, d, *num;
    cin >> q;
    for (int l = 0; l < q; l++)
    {
        cin >> n >> d;
        num = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> num[i];
        }
        if (FoundElementLargerThanD(num, n, d))
        {
            if (FoundTwoElementsAddToDOrLess(num, n, d))
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        else
        {
            cout << "YES" << endl;
        }
    }
}

bool FoundElementLargerThanD(int *num, int n, int d)
{
    for (int i = 0; i < n; i++)
    {
        if (num[i] > d)
            return true;
    }
    return false;
}

bool FoundTwoElementsAddToDOrLess(int *num, int n, int d)
{
    sort(num, num + n);
    if (num[0] + num[1] <= d)
        return true;
    return false;
}
