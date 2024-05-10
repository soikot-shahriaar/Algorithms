// Problem Link:
// https://vjudge.net/contest/575136#problem/F

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 3;

int points[MAXN];

int main()
{

    int t;
    scanf("%d", &t);

    for (int tc = 1; tc <= t; ++tc)
    {
        int n, q;
        scanf("%d %d", &n, &q);

        for (int i = 0; i < n; ++i)
            scanf("%d", points + i);

        printf("Case %d:\n", tc);
        int a, b;

        while (q--)
        {
            scanf("%d %d", &a, &b);

            int *s = lower_bound(points, points + n, a);
            int *t = upper_bound(points, points + n, b);

            printf("%d\n", t - s);
        }
    }

    return 0;
}