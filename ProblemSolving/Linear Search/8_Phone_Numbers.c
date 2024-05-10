// Problem Link:
// https://vjudge.net/contest/575132#problem/H

#include <stdio.h>

#define ll long long
#define ull unsigned long long

int main()
{
    int n, eights = 0;
    char s[100001];
    scanf("%d %s", &n, s);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '8')
        {
            eights++;
        }
    }
    if (eights >= n / 11)
    {
        printf("%d\n", n / 11);
    }
    else if (eights < n / 11 && n > 11)
    {
        printf("%d\n", eights);
    }
    else
    {
        printf("0\n");
    }

    return 0;
}
