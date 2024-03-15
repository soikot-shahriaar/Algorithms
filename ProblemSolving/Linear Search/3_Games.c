// Problem Link:
// https://vjudge.net/problem/CodeForces-268A

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int HU[n]; // HomeUniform
    int GU[n]; // GuestUniform

    for (int i = 0; i < n; i++)
        scanf("%d %d", &HU[i], &GU[i]);

    int gamesGU = 0; // GamesInGuestUniform
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                if (HU[i] == GU[j])
                    gamesGU++;
            }
        }
    }
    printf("%d\n", gamesGU);
    return 0;
}