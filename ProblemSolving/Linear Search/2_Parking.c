// Problem Link:
// https://vjudge.net/contest/575132#problem/B

#include <stdio.h>
int main()
{
    int testCases, numberOfElements, currentElement, maxVal, minVal;
    scanf("%d", &testCases);
    while (testCases--)
    {
        maxVal = 0, minVal = 1000;
        scanf("%d", &numberOfElements);
        while (numberOfElements--)
        {
            scanf("%d", &currentElement);
            if (currentElement > maxVal)
                maxVal = currentElement;
            if (currentElement < minVal)
                minVal = currentElement;
        }
        printf("%d\n", (maxVal - minVal) * 2);
    }
    return 0;
}
