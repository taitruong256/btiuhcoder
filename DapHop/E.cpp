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
    ll n; cin>>n;
    // ll d[n+5];
    // memset(d, 0, sizeof(d));
    // for (ll i=1; i<=n; i++)
    //     for (ll j=i; j<=n; j+=i) d[j]=1-d[j];
    // ll ans=0;
    // for (ll i=1; i<=n; i++) cout<<d[i]<<endl; cout<<endl;
    // for (ll i=1; i<=n; i++) if (d[i]==1) ++ans;
    // cout<<ans;
    //ll n; cin>>n;
    cout<<(n+1)*(n+1)-1;
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