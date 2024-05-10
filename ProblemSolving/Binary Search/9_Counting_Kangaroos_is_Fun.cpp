// Problem Link:
// https://vjudge.net/contest/575136#problem/I

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, r;
int arr[555555];

int main()
{
    int i, j, k;
    cin >> n;
    r = n;
    for (i = 0; i < n; ++i)
        cin >> arr[i];
    sort(arr, arr + n);

    for (i = 0, j = (n + 1) / 2; i < n; ++i)
    {
        if (arr[i] == 0)
            continue;
        for (; j < n && arr[j] < 2 * arr[i]; ++j)
            ;
        if (j < n)
        {
            arr[i] = arr[j] = 0;
            r--;
        }
    }
    printf("%d\n", r);
    return 0;
}
