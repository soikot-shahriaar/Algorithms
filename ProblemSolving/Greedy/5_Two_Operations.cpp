// Problem Link:
// https://vjudge.net/contest/575138#problem/E

#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int l[26] = {};
    for (auto i : s)
        ++l[i - 'a'];
    for (int i = 0; i < 25; ++i)
        l[i + 1] += l[i] / 2, l[i] &= 1;
    for (int i = 25; i >= 0; --i)
        while (l[i]--)
            putchar(i + 'a');
    return 0;
}