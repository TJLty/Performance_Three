//
// Created by TJ_Lty on 2021/6/1.
//

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
static bool operator <(pair<int,int> &a,pair<int,int> &b)
{
    return a.first<b.first;
}
vector<pair<int,int> > elm;
int main()
{
    int a,b;
    while(cin>>a>>b){
        elm.push_back(pair<int,int>(a,b));
    }
    sort(elm.begin(),elm.end());
    int n=elm.size();
    vector<int> dp(n,1);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if (elm[j].second <= elm[i].first) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    cout<<n-*max_element(dp.begin(),dp.end());
    return 0;
}