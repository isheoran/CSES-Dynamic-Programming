#include <bits/stdc++.h>
using namespace std;
#define m (int)(1e9+7)
typedef long long ll;
#define input(v) for (auto &i : v) cin >> i;
#define print(v) for (auto &j : v) cout << j << " "; cout << "\n";
 
#define inf (ll)(1e18)
const int siz=(int)(1e6+1);
ll f[siz];
bool visited[siz];
ll coin[101];
 
ll func(int n,int x)
{
    if(x<0) return inf;
    if(x==0) return 0;
    if(visited[x]) return f[x];
    visited[x]=true;
    for(int i=1;i<=n;i++) f[x]=min(f[x],1+func(n,x-coin[i]));
    return f[x];
}
 
void solve()
{
    int n,x;
    cin>>n>>x;
    for(int i=0;i<siz;i++) f[i]=inf;
    for(int i=1;i<=n;i++) cin>>coin[i];
    cout<<(func(n,x) < inf ? func(n,x) : -1);
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
