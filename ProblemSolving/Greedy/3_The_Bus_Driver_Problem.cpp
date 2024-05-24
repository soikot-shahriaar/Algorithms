// Problem Link:
// https://vjudge.net/contest/575138#problem/C

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
    int n, d, r;
    while (scanf("%d %d %d", &n, &d, &r), n || d || r)
    {
        if (n == 0 && d == 0 && r == 0)
            break;
        int m[100], e[100];
        int hours, ans = 0;
        for (int i = 0; i < n; i++)
            cin >> m[i];
        for (int i = 0; i < n; i++)
            cin >> e[i];

        sort(m, m + n);
        sort(e, e + n, greater<int>());
        for (int i = 0; i < n; i++)
        {
            hours = m[i] + e[i];
            if (hours > d)
                ans += (hours - d) * r;
        }
        cout << ans << endl;
    }
    return 0;
}