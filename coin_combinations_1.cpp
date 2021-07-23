#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod  (int)(1e9+7)
#define sz(s) (int)s.size()
#define all(v) v.begin(),v.end()
#define fill0(dp) memset(dp,0,sizeof(dp))
#define fill(dp) memset(dp,-1,sizeof(dp))
#define input(v) for (auto &i : v) cin >> i;
#define print(v) for (auto &j : v) cout << j << " "; cout << "\n";
vector<int>c(100),dp((int)(1e6)+1,0); 
 
void solve()
{
    int n,x;
    cin>>n>>x;
    for(int i=0;i<n;i++) cin>>c[i];
    dp[0]=1;
    for(int i=1;i<=x;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i-c[j]>=0)
            {
                (dp[i] += dp[i-c[j]])%=mod;
            }
        }
    }
    cout<<dp[x]<<"\n";
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
