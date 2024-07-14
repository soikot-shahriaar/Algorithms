// Problem Link:
// https://vjudge.net/contest/575161#problem/O

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define dsort(a, n) sort(a, a + n, greater<int>())

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    dsort(a, n);
    ll ans = 0;
    for (ll i = 0; i < n; i += 2)
        ans += (a[i] - a[i + 1]);
    cout << ans << endl;
}
