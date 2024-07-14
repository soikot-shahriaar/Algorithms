// Problem Link:
// https://vjudge.net/contest/575132#problem/G

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int ct = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '1')
                ct++;
        }
        int index;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '1')
            {
                index = i;
                break;
            }
        }
        int check = 0;
        for (int i = index; i < s.length(); i++)
        {
            if (s[i] == '1')
                check++;
            else
                break;
        }
        if (check == ct && ct > 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}