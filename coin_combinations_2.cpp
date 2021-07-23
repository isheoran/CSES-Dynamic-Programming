#include <bits/stdc++.h>
using namespace std;
#define mod  (int)(1e9+7)
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
    vector<int>c(n);
    input(c);
    vector<vector<int>>dp(n+1,vector<int>(x+1,0));
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=x;j++)
        {
            dp[i][j] = dp[i-1][j];
            if(j-c[i-1]>=0)
            {
                (dp[i][j] += dp[i][j-c[i-1]])%=mod;
            }
        }
    }
    cout<<dp[n][x];
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
