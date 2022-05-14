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
    ll n, m; scanf("%lld", &n);
    m=(ll)log2(n);
    ll a[n+5], sparse[n+5][17];
    for (ll i=1; i<=n; i++)
    {
        scanf("%lld", &a[i]);
        sparse[i][0]=a[i];
    }
    for (ll j=1; j<=m; j++)
        for (ll i=1; i+(1<<j)-1<=n; i++)
            sparse[i][j]=__gcd(sparse[i][j-1], sparse[i+(1<<(j-1))][j-1]);

    ll q; scanf("%lld", &q);
    lg[1] = 0;
    for (int i = 2; i <= n; ++i) lg[i] = lg[i / 2] + 1;
    for (ll i=1; i<=q; i++)
    {
        ll l, r; scanf("%lld%lld", &l, &r);
        ll length=r-l+1;
        ll k = lg[k];
        printf("%lld\n", __gcd(sparse[l][k], sparse[r-(1<<k)+1][k]));
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