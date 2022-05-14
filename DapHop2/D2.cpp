/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, q;
vector<vector<ll>> tree(400005);
ll a[100005];

vector<ll> merge(vector<ll> a, vector<ll> b)
{
    ll i=0, j=0;
    vector<ll> ans;
    while (i<a.size() && j<b.size())
    {
        if (a[i]<b[j]) 
        {
            ans.push_back(a[i]);
            ++i;
        }
        else
        {
            ans.push_back(b[j]);
            ++j;
        }
    }
    while (i<a.size()) ans.push_back(a[i]), ++i;
    while (j<b.size()) ans.push_back(b[j]), ++j;
    for (auto it: ans) cout<<it<<" "; cout<<endl;
    return ans;
}

void build(ll id, ll l, ll r) {
    if (l == r) {
        tree[id].push_back(a[l]);
        return ;
    }
    ll mid = (l + r) / 2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);

    tree[id]=merge(tree[id*2], tree[id*2+1]);
}

ll get(ll id, ll l, ll r, ll u, ll v, ll k) {
    if (v < l || r < u) return 0;
    if (u <= l && r <= v) 
        return tree[id].size() - (upper_bound(tree[id].begin(), tree[id].end(), k) - tree[id].begin());
    ll mid = (l + r) / 2;
    return get(id*2, l, mid, u, v, k) + get(id*2+1, mid+1, r, u, v, k);
}

void solve()
{
    cin>>n>>q;
    for (ll i=1; i<=n; i++) cin>>a[i];
    build(1, 1, n);
    ll dp[n+5], sum[n+5];
    sum[0]=0;
    for (ll i=1; i<=n; i++) dp[i]=get(1, 1, n, 1, i, a[i]);
    for (ll i=1; i<=n; i++) sum[i]=sum[i-1]+dp[i];
    // for (ll i=1; i<=n; i++) cout<<dp[i]<<" "; cout<<endl;
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