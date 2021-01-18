#include <iostream>
using namespace std;

int findMin(int a, int b, int c);
int attemptFeed(int a, int b, int c, int *order, int start);
int main()
{
    int a, b, c, max = 0, days = 0;
    cin >> a >> b >> c;
    int weeksA = a / 3;
    int weeksB = b / 2;
    int weeksC = c / 2;
    int weeks = findMin(weeksA, weeksB, weeksC);
    days += weeks * 7;
    a = a - weeks * 3;
    b = b - weeks * 2;
    c = c - weeks * 2;
    int *rotation = new int[7]{1, 2, 3, 1, 3, 2, 1};
    for (int i = 0; i < 7; i++)
    {
        int days = attemptFeed(a, b, c, rotation, i);
        max = days > max ? days : max;
    }
    cout << max + days << endl;
}

int attemptFeed(int a, int b, int c, int *order, int start)
{
    int days = 0;
    while (true)
    {
        for (int i = start; i < 7; i++)
        {
            switch (order[i])
            {
            case 1:
                if (a > 0)
                {
                    a--;
                    days++;
                }
                else
                {
                    return days;
                }
                break;
            case 2:
                if (b > 0)
                {
                    b--;
                    days++;
                }
                else
                {
                    return days;
                }
                break;
            case 3:
                if (c > 0)
                {
                    c--;
                    days++;
                }
                else
                {
                    return days;
                }
                break;
            }
        }
        start = 0;
    }
}

int findMin(int a, int b, int c)
{
    int min = a;
    if (b < min)
        min = b;
    if (c < min)
        min = c;
    return min;
}
