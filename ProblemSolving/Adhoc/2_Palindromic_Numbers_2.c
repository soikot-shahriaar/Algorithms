// Problem Link:
// https://vjudge.net/contest/575128#problem/B

#include <stdio.h>
#include <string.h>

int main()
{
    int TC; 
    scanf("%d", &TC);
    for (int k = 1; k <= TC; k++)
    {
        char str[100];
        char flag = 0;
        scanf("%s", str);
        
        for (int i = 0; i < strlen(str) / 2; i++)
        {
            if (str[i] != str[strlen(str) - 1 - i])
            {
                printf("Case %d: No\n", k);
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            printf("Case %d: Yes\n", k);
    }
    return 0;
}