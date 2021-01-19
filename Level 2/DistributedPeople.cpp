#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
    int n, prev = 0, removed = 0, continuous = 0, *flat;
    cin >> n;
    flat = new int(n);
    for (int i = 0; i < n; i++)
    {
        cin >> flat[i];
    }
    for (int i = 1; i < n - 1; i++)
    {
        if (flat[i] == 0 && flat[i - 1] == 1 && flat[i + 1] == 1)
        {
            prev = i;
            continuous = 1;
            break;
        }
    }

    int move = prev + 2;
    while (move < n - 1)
    {
        if (flat[move] == 0 && flat[move - 1] == 1 && flat[move + 1] == 1)
        {
            if (prev == move - 2)
            {
                continuous++;
            }
            else
            {
                removed += continuous > 1 ? (continuous / 2) : 1;
                if (continuous > 1 && continuous & 1)
                {
                    removed++;
                }
                continuous = 1;
            }
            prev = move;
        }
        move++;
    }

    removed += continuous > 1 ? (continuous / 2) : continuous;
    if (continuous > 1 && continuous & 1)
    {
        removed++;
    }
    cout << removed << endl;
}
