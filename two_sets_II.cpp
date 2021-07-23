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
int dp[500][125000];
 
int f(int i,int sum)
{
	if(sum == 0) return 1;
	if(i < 0 or sum<0) return 0;
	if(dp[i][sum]!=-1) return dp[i][sum];
	return dp[i][sum] = (f(i-1,sum) + f(i-1,sum-i))%mod;
}
 
void solve()
{
    int n;
    cin>>n;
    int target = (n+1)*n/2;
	if(target & 1)
	{
		cout<<"0\n";
		return;
	}
	target/=2;
    fill(dp);
	cout<<f(n-1,target);
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
