// Problem Link:
// https://vjudge.net/contest/575132#problem/A

#include <stdio.h>
int main()
{
    int TC;
    scanf("%d", &TC);
    for (int i = 1; i <= TC; i++)
    {
        int n;
        scanf("%d", &n);
        int max = 0;
        for (int i = 0; i < n; i++)
        {
            int a;
            scanf("%d", &a);

            if (a > max)
                max = a;
        }
        printf("Case %d: %d\n", i, max);
    }
}