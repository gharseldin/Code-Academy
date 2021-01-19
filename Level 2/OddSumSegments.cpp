#include <iostream>

using namespace std;

typedef long long ll;

void prefixSum(int *num, int n);
void permutate(int *num, int n, int position, int k, int *section, bool odd, int barrier);

int main()
{
    int q, n, k, *num, *section;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> n >> k;
        num = new int(n);
        section = new int(k);
        for (int j = 0; j < k; j++)
            section[j] = -1;
        for (int j = 0; j < n; j++)
            cin >> num[j];
        prefixSum(num, n);
        permutate(num, n, 0, k, section, true, 0);
        if (section[k - 1] == n)
        {
            cout << "YES" << endl;
            for (int l = 0; l < k; l++)
            {
                cout << section[l] << (l == k - 1 ? "\n" : " ");
            }
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}

void prefixSum(int *num, int n)
{
    for (int i = 1; i < n; i++)
    {
        num[i] = num[i] + num[i - 1];
    }
}

void permutate(int *num, int n, int position, int k, int *section, bool odd, int barrier)
{
    if (k < n)
        return;
    for (int i = 0; i < k - 1; i++)
        section[i] = i;
}

//void permutate(int *num, int n, int position, int k, int *section, bool odd, int barrier){
//    if(section[k-1] == n)
//        return;
//    if(position == n)
//        return;
//    if(barrier == k)
//        return;
//    if(odd){
//        while(position<n && !(num[position]&1)){
//            position++;
//        }
//        section[barrier] = position;
//        permutate(num, n, position+1, k, section, !odd, barrier+1);
//        if(section[k-1] == n)
//            return;
//        section[barrier] = -1;
//        permutate(num, n, position+1, k, section, odd, barrier);
//    }else{
//        while(position<n && (num[position]&1)){
//            position++;
//        }
//        section[barrier] = position;
//        permutate(num, n, position+1, k, section, !odd, barrier+1);
//        if(section[k-1] == n)
//            return;
//        section[barrier] = -1;
//        permutate(num, n, position+1, k, section, odd, barrier);
//    }
//}
