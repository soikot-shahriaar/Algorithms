// Problem Link:
// https://vjudge.net/contest/575128#problem/B

#include <stdio.h>

int isPalindrome(int n)
{
    int reverse = 0;
    int original = n;

    while (n > 0)
    {
        int digit = n % 10;
        reverse = reverse * 10 + digit;
        n /= 10;
    }

    if (original == reverse)
        return 1;
    else
        return 0;
}

int main()
{
    int TC; 
    scanf("%d", &TC);

    for (int i = 1; i <= TC; i++)
    {
        int n;
        scanf("%d", &n);

        if (isPalindrome(n))
            printf("Case %d: Yes\n", i);
        else
            printf("Case %d: No\n", i);
    }
    return 0;
}