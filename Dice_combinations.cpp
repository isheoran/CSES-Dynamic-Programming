#include <bits/stdc++.h>
using namespace std;
#define m (int)(1e9+7)
typedef long long ll;
#define input(v) for (auto &i : v) cin >> i;
#define print(v) for (auto &j : v) cout << j << " "; cout << "\n";
 
const int siz=(int)(1e6+1);
ll f[siz];
bool visited[siz];
 
int func(int n)
{
    if(n<0) return 0;
    if(n==0) return 1;
    if(visited[n]) return f[n];
    visited[n]=true;
    for(int i=1;i<=6;i++) f[n] = (f[n]%m+func(n-i)%m)%m;
    return f[n];
}
 
void solve()
{
    int n;
    cin>>n;
    cout<<func(n);
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
