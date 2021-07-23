#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod   (int)(1e9+7)
#define sz(s) (int)s.size()
#define all(v) v.begin(),v.end()
#define fill0(dp) memset(dp,0,sizeof(dp))
#define fill(dp) memset(dp,-1,sizeof(dp))
#define input(v) for (auto &i : v) cin >> i;
#define print(v) for (auto &j : v) cout << j << " "; cout << "\n";
vector<int>x;
int n,m;
int dp[(int)(1e5)+1][101];
 
int f(int i,int back)
{
    if(back < 1 or back > m) return 0;
    if(i==n) return 1;
    if(dp[i][back]!=-1) return dp[i][back]%mod;
    if(x[i])
    {
        if(abs(x[i]-back)>1) return 0;
        else
        {
            return dp[i][back] = f(i+1,x[i])%mod;
        }
    }
    else
    {
        return dp[i][back] = (f(i+1,back)%mod+f(i+1,back-1)%mod+f(i+1,back+1)%mod)%mod;
    }
}
 
void solve()
{
    fill(dp);
    cin>>n>>m;
    x.resize(n);
    input(x);
    int ans=0;
    if(x[0]) cout<<f(1,x[0]);
    else
    {
        for(int i=1;i<=m;i++)
        {
            ans = (ans + f(1,i)%mod)%mod;
        }
        cout<<ans%mod<<"\n";
        exit(0);
    }
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
