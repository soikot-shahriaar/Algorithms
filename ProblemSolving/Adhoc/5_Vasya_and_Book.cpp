// Problem Link:
// https://vjudge.net/contest/575128#problem/E

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll n, x, y, d, t;
    cin >> t;
    while (t--)
    {
        cin >> n >> x >> y >> d;
        if (abs(y - x) % d == 0)
            printf("%lld\n", abs(y - x) / d);
        else
        {
            ll ans = ll(1e18);
            if ((y - 1) % d == 0)
                ans = min(ans, (y - 1) / d + (x - 1 + d - 1) / d);
            if ((n - y) % d == 0)
                ans = min(ans, (n - y) / d + (n - x + d - 1) / d);
            if (ans == ll(1e18))
                puts("-1");
            else
                printf("%lld\n", ans);
        }
    }
    return 0;
}