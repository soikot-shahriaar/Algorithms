// Problem Link:
// https://vjudge.net/contest/575161#problem/I

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 95 + 10;
#define pii pair<int, int>
#define MOD 10000007
#define PI acos(-1.0)

int check(string s)
{
    int num, ans = 0;
    for (int i = s.size() - 1, j = 0; i >= 0 && j <= s.size() - 1; i--, j++)
    {
        num = s[i] - '0';
        ans += (pow(2, j) * num);
    }
    return ans;
}

int main()
{
    int t, cs = 1, a, b, c, d;
    scanf("%d", &t);

    while (t--)
    {
        string s1, s2, s3, s4;

        scanf("%d.%d.%d.%d\n", &a, &b, &c, &d);

        getline(cin, s1, '.');
        getline(cin, s2, '.');
        getline(cin, s3, '.');
        getline(cin, s4, '\n');

        if (a == check(s1) && b == check(s2) && c == check(s3) && d == check(s4))
        {
            printf("Case %d: Yes\n", cs++);
        }
        else
        {
            printf("Case %d: No\n", cs++);
        }
    }
}