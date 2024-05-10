// Problem Link:
// https://vjudge.net/contest/575136#problem/D

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int y, p, i;
    while (cin >> y) // Input may contain many test cases
    {
        cin >> p;
        int arr[p];
        for (i = 0; i < p; i++)
        {
            cin >> arr[i];
        }
        int st = 0, end = 0;
        int max = 0, max_st, max_end;
        max = 1;
        max_st = arr[0];
        max_end = arr[0];
        while (end < (p - 1)) // p-1 to ensure that the array limits are not exceeded
        {
            end++;
            while ((arr[end] - arr[st]) >= y)
            {
                st++;
            }
            if ((end - st + 1) > max) // end-st+1 to count the difference // end-st would be wrong
            {
                max = end - st + 1;
                max_st = arr[st];
                max_end = arr[end];
            }
        }
        cout << max << " " << max_st << " " << max_end << endl;
    }
    return 0;
}