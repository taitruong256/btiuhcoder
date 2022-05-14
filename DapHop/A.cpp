/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef int ll;

void solve()
{
    ll n, m; cin>>n>>m;
    ll a[n+5][m+5];
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=m; j++) a[i][j]=0;
    
    ll q; cin>>q;
    for (ll i=1; i<=q; i++)
    {
        char c; ll x; cin>>c>>x;
        if (c=='C')
            for (ll j=1; j<=n; j++) a[j][x]=1-a[j][x];
        else 
            for (ll j=1; j<=m; j++) a[x][j]=1-a[x][j];

        // for (ll k=1; k<=n; k++)
        // {
        //     for (ll j=1; j<=m; j++) cout<<a[k][j]<<" ";
        //     cout<<endl;
        // }      cout<<endl;
    }

    

    ll ans=0;
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=m; j++) if (a[i][j]==1) ++ans;
    cout<<ans;
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