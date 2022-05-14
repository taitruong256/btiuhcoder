/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool cmp2(pair<ll, ll> a, pair<ll, ll> b)
{
    if (a.second==b.second) return a.first<b.first;
    return a.second<b.second;
}

void solve()
{
    ll n; cin>>n;
    pair<ll, ll> a[2*n+5];
    for (ll i=0; i<2*n; i++) cin>>a[i].first>>a[i].second;
    ll ans1=0;
    sort(a, a+2*n);
    for (ll i=0; i<n; i++) ans1+=a[i].first;
    for (ll i=n; i<2*n; i++) ans1+=a[i].second;

    ll ans2=0;
    sort(a, a+2*n, cmp2);
    for (ll i=0; i<n; i++) ans2+=a[i].first;
    for (ll i=n; i<2*n; i++) ans2+=a[i].second;
    cout<<min(ans1, ans2);
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