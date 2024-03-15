// Problem Link: 
// https://vjudge.net/contest/575128#problem/A

#include <stdio.h>

int squares(int n)
{
    if (n == 1)
        return 1;
    else
        return squares(n - 1) + 4 * (n - 1);
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", squares(n));
}