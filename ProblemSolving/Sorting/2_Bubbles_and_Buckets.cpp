// Problem Link:
// https://vjudge.net/contest/575137#problem/B

#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

long long cnt;
vector<int> mrge(const vector<int>& left, const vector<int>& right)
{
    vector<int> result;
    unsigned left_it = 0, right_it = 0;
    int ll=left.size(), rl=right.size();

    while(left_it <ll && right_it < rl)
    {
        if(left[left_it] < right[right_it])
        {
            result.push_back(left[left_it]);
            left_it++;
        }
        else
        {
            result.push_back(right[right_it]);
            right_it++;
            cnt+=(ll-left_it);
        }
    }

    while(left_it < left.size())
    {
        result.push_back(left[left_it]);
        left_it++;
    }

    while(right_it < right.size())
    {
        result.push_back(right[right_it]);
        right_it++;
    }

    return result;
}

vector<int> merge_sort(vector<int>& vec)
{
    if(vec.size() == 1) return vec;

    vector<int>::iterator middle = vec.begin() + (vec.size() / 2);
    vector<int> left(vec.begin(), middle);
    vector<int> right(middle, vec.end());

    left = merge_sort(left);
    right = merge_sort(right);

    return mrge(left, right);
}


int main()
{
    int n,x;
    while(scanf("%d",&n)==1 && n)
    {
        vector<int>v;
        cnt=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            v.push_back(x);
        }
        vector<int> res=merge_sort(v);

        //printf("%lld\n",cnt);
        if(cnt%2) cout<<"Marcelo"<<endl;
        else cout<<"Carlos"<<endl;
    }
    return 0;
}