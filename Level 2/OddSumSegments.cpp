#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
    int q, n, k, *num, *section, counter = 0, sum = 0;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> n >> k;
        if (k > n)
        {
            cout << "NO" << endl;
            return 0;
        }
        num = new int[n];
        section = new int[k];
        for (int j = 0; j < k; j++)
            section[j] = -1;
        for (int j = 0; j < n; j++)
            cin >> num[j];
        int position = 0;
        while (position < n)
        {
            if (counter < k - 1)
            {
                if (num[position] & 1)
                {
                    section[counter] = position + 1;
                    counter++;
                }
            }
            else
            {
                break;
            }
            position++;
        }
        while (position < n)
        {
            if (num[position] & 1)
            {
                sum++;
            }
            position++;
        }
        if (sum & 1)
        {
            cout << "YES" << endl;
            for (int m = 0; m < k - 1; m++)
                cout << section[m] << " ";
            cout << n << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        sum = 0;
        counter = 0;
    }
}
