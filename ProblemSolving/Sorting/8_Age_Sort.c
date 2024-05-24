// Problem Link:
// https://vjudge.net/contest/575137#problem/H

#include <stdio.h>
int main()
{
    int age, i, j, n;
    while (scanf("%d", &n) != EOF && n != 0)
    {
        int a[101] = {0}, m = 0;
        for (i = 1; i <= n; i++)
        {
            scanf("%d", &age);
            m++;
            a[age] = a[age] + 1;
        }
        m--;
        for (i = 1; i <= 100; i++)
        {
            if (a[i] > 0)
            {
                for (j = 1; j <= a[i]; j++)
                {
                    printf("%d", i);
                    while (m--)
                    {
                        printf(" ");
                        break;
                    }
                }
            }
        }
        printf("\n");
    }
    return 0;
}