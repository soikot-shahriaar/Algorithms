// Problem Link:
// https://vjudge.net/contest/575128#problem/C

#include <stdio.h>
int main()
{
    int TC, MP, LP; // ManPostion, LiftPostion
    scanf("%d", &TC);

    for (int i = 1; i <= TC; i++)
    {
        scanf("%d %d", &MP, &LP);

        int floor, ground, time;
        if (MP != 0 && MP != LP)
        {
            int floor, ground, time;
            if (MP > LP)
            {
                floor = MP - LP;
                ground = MP - 0;
                time = (floor * 4) + (ground * 4) + 19;
                printf("Case %d: %d\n", i, time);
            }
            else
            {
                floor = LP - MP;
                ground = MP - 0;
                time = (floor * 4) + (ground * 4) + 19;
                printf("Case %d: %d\n", i, time);
            }
        }
        else if (MP != 0 && MP == LP)
        {
            ground = MP - 0;
            time = (ground * 4) + 19;
            printf("Case %d: %d\n", i, time);
        }
    }
    return 0;
}