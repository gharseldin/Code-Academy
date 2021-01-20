#include <iostream>

using namespace std;

int main()
{
    int q, n, *num;
    long long sum = 0;
    cin >> q;
    for (int l = 0; l < q; l++)
    {
        cin >> n;
        num = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> num[i];
        }
        for (int i = 0; i < n; i++)
        {
            sum += num[i];
        }
        string result = "NO";
        if (sum & 1)
        {
            result = "YES";
        }
        else
        {
            if (num[0] & 1)
            {
                for (int i = 1; i < n; i++)
                {
                    if (!(num[0] & 1))
                    {
                        result = "YES";
                        break;
                    }
                }
            }
            else
            {
                for (int i = 1; i < n; i++)
                {
                    if (num[0] & 1)
                    {
                        result = "YES";
                        break;
                    }
                }
            }
        }
        cout << result << endl;
        sum = 0;
    }
}
