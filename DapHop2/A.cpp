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
    ll a[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    ll q; cin>>q;
    for (ll i=1; i<=q; i++)
    {
        ll t, x, y; cin>>t>>x>>y;
        if (t==1) swap(a[x], a[y]);
        else 
        {
            vector<ll> v;
            for (ll j=x; j<=y; j++) v.push_back(a[j]);
            sort(v.begin(), v.end());
            bool check=true;
            for (ll j=0; j<v.size(); j++) 
            {
                // cout<<v[j]<<" ";
                if (v[j]!=v[0]+j) check=false;
            }
            if (check==true) cout<<"YES\n";
            else cout<<"NO\n";
        }
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