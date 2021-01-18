#include <iostream>

using namespace std;

int main()
{
    bool counting = false;
    int n, count = 0, removed = 0;
    string file;
    cin >> n >> file;
    for (int i = 0; i < n; i++)
    {
        if (file[i] == 'x')
        {
            if (counting)
            {
                count++;
            }
            else
            {
                count = 1;
                counting = true;
            }
        }
        else
        {
            if (counting)
            {
                counting = false;
                if (count > 2)
                    removed += count - 2;
                count = 0;
            }
        }
    }
    if (counting && count > 2)
    {
        removed += count - 2;
    }
    cout << removed << endl;
}
