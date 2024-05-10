// Problem Link:
// https://vjudge.net/contest/575136#problem/A

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t, n, test = 0;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int k = 0, ans;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] - a[i - 1] > k)
                k = a[i] - a[i - 1];
        }
        ans = k;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] - a[i - 1] == k)
                k--;
            else if (a[i] - a[i - 1] > k)
            {
                ans++;
                break;
            }
        }
        cout << "Case " << ++test << ": " << ans << endl;
    }
    return 0;
}
