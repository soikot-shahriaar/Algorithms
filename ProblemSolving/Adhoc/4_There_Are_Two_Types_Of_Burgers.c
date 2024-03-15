// Problem Link:
// https://vjudge.net/contest/575128#problem/D

#include <stdio.h>
int main()
{

    // TestCase, NumberOfBun, Chicken, Beef, HamBurger, ChickenBurger
    int TC, NoB, Ck, Bf, HmB, CkB;
    scanf("%d", &TC);

    for (int i = 1; i <= TC; i++)
    {
        int total_price = 0;
        scanf("%d %d %d", &NoB, &Bf, &Ck);
        scanf("%d %d", &HmB, &CkB);
        if (HmB > CkB)
        {
            while (NoB > 1 && Bf > 0)
            {
                total_price += HmB;
                NoB = NoB - 2;
                Bf--;
            }
            while (NoB > 1 && Ck > 0)
            {
                total_price += CkB;
                NoB = NoB - 2;
                Ck--;
            }
        }
        else
        {
            while (NoB > 1 && Ck > 0)
            {
                total_price += CkB;
                NoB = NoB - 2;
                Ck--;
            }
            while (NoB > 1 && Bf > 0)
            {
                total_price += HmB;
                NoB = NoB - 2;
                Bf--;
            }
        }
        printf("%d\n", total_price);
    }
    return 0;
}