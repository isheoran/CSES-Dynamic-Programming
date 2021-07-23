#include <bits/stdc++.h>
using namespace std;
#define inf   (int)(1e9+7)
#define sz(s) (int)s.size()
#define all(v) v.begin(),v.end()
#define fill0(dp) memset(dp,0,sizeof(dp))
#define fill(dp) memset(dp,-1,sizeof(dp))
#define input(v) for (auto &i : v) cin >> i;
#define print(v) for (auto &j : v) cout << j << " "; cout << "\n";
 
void solve()
{
    int n,x;
    cin>>n>>x;
    vector<int>h(n),s(n);
    input(h);
    input(s);
    vector<vector<int>>dp(n,vector<int>(x+1,0));
    for(int j=1;j<=x;j++)
    {
        if(j>=h[0]) dp[0][j]=s[0];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=x;j++)
        {
            if(j-h[i]>=0)
            {
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-h[i]]+s[i]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout<<dp[n-1][x];
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int testcases=1;
    //cin>>testcases;
    while(testcases--) solve();
    return 0;
}
