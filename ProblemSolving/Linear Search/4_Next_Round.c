// Problem Link:
// https://vjudge.net/contest/575132#problem/D

#include <stdio.h>

int main()
{
    int n, k; // NumberOfScores, IndexOfInterest
    scanf("%d %d", &n, &k);

    int scores[n];
    int scr_count = 0;

    for (int i = 0; i < n; i++)
        scanf("%d", &scores[i]);

    for (int i = 0; i < n; i++)
    {
        if (scores[i] >= scores[k - 1] && scores[i] > 0)
            scr_count++;
    }

    printf("%d\n", scr_count);
    return 0;
}
