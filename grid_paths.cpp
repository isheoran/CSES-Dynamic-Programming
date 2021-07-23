#include <bits/stdc++.h>
using namespace std;
#define m (int)(1e9+7)
typedef long long ll;
#define input(v) for (auto &i : v) cin >> i;
#define print(v) for (auto &j : v) cout << j << " "; cout << "\n";
char a[1001][1001];
ll f[1001][1001];
bool visited[1001][1001];
 
ll func(ll n,ll i,ll j)
{
    if(i>n || j>n) return 0;
    if(a[i][j]=='*') return 0;
    if(i==n and j==n) return 1;
    if(visited[i][j]) return f[i][j];
    visited[i][j]=true;
    return f[i][j] = (func(n,i+1,j)%m+func(n,i,j+1)%m)%m;
}
 
void solve()
{
    ll n;
    cin>>n;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    cin>>a[i][j];
    cout<<func(n,1,1);
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int testcases=1;
    //cin>>testcases;
    while(testcases--) solve();
    return 0;
}
