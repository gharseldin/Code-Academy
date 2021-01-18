#include <iostream>

using namespace std;

int main()
{
    bool resting = false;
    int n, *hour, max = 0, count = 0;
    cin >> n;
    hour = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> hour[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (hour[i] == 1)
        {
            if (resting)
            {
                count++;
            }
            else
            {
                resting = true;
                count = 1;
            }
        }
        else
        {
            if (resting)
            {
                max = count > max ? count : max;
                resting = false;
            }
        }
    }
    if (resting)
    {
        int i = 0;
        while (hour[i++] == 1)
        {
            count++;
        }
        max = count > max ? count : max;
    }
    cout << max << endl;
}
