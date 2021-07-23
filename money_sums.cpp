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
vector<int>x;
vector<vector<int>>dp;
 
bool f(int sum,int i)
{
    if(sum == 0) return true;
    if(i<0 or sum<0) return false;
    if(dp[sum][i]!=-1) return dp[sum][i];
    return (dp[sum][i] = (f(sum,i-1) | f(sum-x[i],i-1)));
}
 
void solve()
{
    int n,num,sum=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>num;
        x.push_back(num);
        sum += num;
    }
    dp.assign(sum+1,vector<int>(n,-1));
    int cnt=0;
    for(int i=sum;i>=1;i--) if(f(i,n-1)) cnt++;
    cout<<cnt<<"\n";
    for(int i=1;i<=sum;i++) if(dp[i][n-1]) cout<<i<<" ";
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
