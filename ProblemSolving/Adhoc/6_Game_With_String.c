// Problem Link:
// https://vjudge.net/contest/575128#problem/F

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long ll;

int main()
{
    fast();
    char s[100001];
    scanf("%s", s);
    ll count = 0;
    int top = -1;
    char stack[100001];

    for (ll i = 0; i < strlen(s); i++)
    {
        if (top == -1)
        {
            stack[++top] = s[i];
        }
        else
        {
            char ele = stack[top];
            if (ele == s[i])
            {
                top--;
                count ^= 1;
            }
            else
            {
                stack[++top] = s[i];
            }
        }
    }

    if (count)
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
