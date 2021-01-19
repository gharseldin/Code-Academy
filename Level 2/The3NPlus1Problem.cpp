#include <iostream>
using namespace std;

int findCycleLength(int num);
int main()
{
    int i, j, i2, j2, cycle = 0;
    while (cin >> i >> j)
    {

        if (i < j)
        {
            i2 = i;
            j2 = j;
        }
        else
        {
            i2 = j;
            j2 = i;
        }
        for (int k = i2; k <= j2; k++)
        {
            int temp = findCycleLength(k);
            cycle = temp > cycle ? temp : cycle;
        }
        cout << i << " " << j << " " << cycle << endl;
        cycle = 0;
    }
}

int findCycleLength(int num)
{
    long long numb = num;
    int length = 1;
    while (numb != 1)
    {
        length++;
        if (numb & 1)
        {
            numb = 3 * numb + 1;
        }
        else
        {
            numb /= 2;
        }
    }
    return length;
}
