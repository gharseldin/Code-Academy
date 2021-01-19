#include <iostream>
using namespace std;

void attempt(int n, int m, int counter, int &ops, int *visited);
int main()
{
    int n, m, ops = INT_MAX, *visited;
    cin >> n >> m;
    if (m > n)
    {
        visited = new int[2 * m + 1];
        for (int i = 0; i < 2 * m + 1; i++)
            visited[i] = INT_MAX;
    }
    else
    {
        visited = new int[n + 1];
        for (int i = 0; i < n + 1; i++)
            visited[i] = INT_MAX;
    }

    attempt(n, m, 0, ops, visited);
    cout << ops << endl;
}
void attempt(int n, int m, int counter, int &ops, int *visited)
{
    if (n > 0 && visited[n] >= counter)
    {
        visited[n] = counter;
        if (n == m)
        {
            if (counter < ops)
            {
                ops = counter;
            }
        }
        else if (n > m)
        {
            attempt(n - 1, m, counter + 1, ops, visited);
        }
        else
        {
            attempt(n * 2, m, counter + 1, ops, visited);
            attempt(n - 1, m, counter + 1, ops, visited);
        }
    }
}
