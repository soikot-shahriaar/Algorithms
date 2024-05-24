// Problem Link:
// https://vjudge.net/contest/575138#problem/J

#include <bits/stdc++.h>
#include <stdio.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;

#define ll long long
#define scl(n) scanf("%lld", &n)
#define scll(n, m) scanf("%lld%lld", &n, &m)
#define scc(c) scanf("%c", &c)
#define fr(i, n) for (ll i = 0; i < n; i++)
#define fr1(i, n) for (ll i = 1; i <= n; i++)
#define pfl(x) printf("%lld\n", x)
#define pb push_back
#define debug cout << "I am here" << endl;
#define pno cout << "NO" << endl
#define pys cout << "YES" << endl
#define tcas(i, t) for (ll i = 1; i <= t; i++)
#define all(x) (x).begin(), (x).end()
#define pr pair<ll, ll>
#define ff first
#define ss second

int main()
{
    ll t;
    cin >> t;
    tcas(cs, t)
    {
        ll m, n, b, c, d, i, j, k, x, y, z, l, r, p, q;
        string s, s1, s2, s3, s4;

        ll cnt = 0, cn = 0, ans = 0, sum = 0;
        cin >> s >> s1;
        n = s.size();

        fr(i, n)
        {
            x = i;
            for (j = n - 1; j > i; j--)
            {
                if (s[j] < s[x])
                    x = j;
            }

            if (x != i)
            {
                swap(s[x], s[i]);
                break;
            }
        }

        if (s < s1)
            cout << s << endl;
        else
            cout << "---" << endl;
    }

    return 0;
}