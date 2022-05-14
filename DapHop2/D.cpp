/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, q; cin>>n>>q;
    ll a[n+5], dp[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    dp[0]=0;
    stack<ll> st;
    for (ll i=1; i<=n; i++)
    {
        ll cnt=0;
        for (ll j=1; j<i; j++) if (a[j]>a[i]) ++cnt; 
        dp[i]=cnt; 
    }
    // for (ll i=1; i<=n; i++) cout<<dp[i]<<" "; cout<<endl;

    ll sum[n+5];
    sum[0]=0;
    for (ll i=1; i<=n; i++) sum[i]=sum[i-1]+dp[i];
    for (ll i=1; i<=q; i++)
    {
        ll x, y; cin>>x>>y;
        cout<<sum[y]-sum[x-1]<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}