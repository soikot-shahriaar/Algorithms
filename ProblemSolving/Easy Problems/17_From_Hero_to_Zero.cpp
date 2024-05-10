// Problem Link:
// https://vjudge.net/contest/575161#problem/Q

#include <bits/stdc++.h>
using namespace std;
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL));

unsigned long long n, k, ans;
int main()
{
    fastread();
    int t;
    cin >> t;
    while (t--)
    {
        ans = 0;
        cin >> n >> k;
        while (n > 0)
        {
            if (n % k == 0)
            {
                n /= k;
                ans++;
            }
            else if (n % k != 0)
            {
                long long over = n % k;
                n -= over;
                ans += over;
            }
            if (n == 0)
            {
                break;
            }
        }

        cout << ans << endl;
    }
}