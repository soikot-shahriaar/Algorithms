// Problem Link:
// https://vjudge.net/contest/575161#problem/D

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a[5];
    for (int i = 0; i < 4; i++)
        cin >> a[i];

    sort(a, a + 4);
    for (int i = 0; i < 3; i++)
        cout << a[3] - a[i] << " ";
    cout << endl;
}