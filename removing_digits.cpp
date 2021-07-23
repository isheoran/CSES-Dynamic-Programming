#include <bits/stdc++.h>
using namespace std;
#define m (int)(1e9+7)
typedef long long ll;
#define input(v) for (auto &i : v) cin >> i;
#define print(v) for (auto &j : v) cout << j << " "; cout << "\n";
 
int max_digit(int n)
{
    int mx = 0;
    while(n)
    {
        mx=max(mx,n%10);
        n/=10;
    }
    return mx;
}
 
void solve()
{
    int n;
    cin>>n;
    int cnt = 0;
    while(n)
    {
        n-=max_digit(n);
        cnt++;
    }
    cout<<cnt;
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
