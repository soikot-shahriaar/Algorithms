// Problem Link:
// https://vjudge.net/contest/575161#problem/N

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int j = 2;
    for (int i = 0; i < n;)
    {
        cout << s.at(i);
        i = i + j;
        j++;
    }
    cout << endl;
    return 0;
}