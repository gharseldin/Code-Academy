#include <iostream>

using namespace std;

int main()
{
    int n, *numbers, *result, counter = 0, total = 1;
    cin >> n;
    numbers = new int[n];
    result = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
        result[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (numbers[i] == numbers[j])
                break;
            if (j == n - 1)
            {
                total++;
                result[counter++] = numbers[i];
            }
        }
    }
    result[counter++] = numbers[n - 1];
    cout << total << endl;
    for (int i = 0; i < total; i++)
    {
        cout << result[i] << (i == total - 1 ? "\n" : " ");
    }
}
