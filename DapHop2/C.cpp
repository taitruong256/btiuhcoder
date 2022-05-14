/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n' 
typedef int ll;
ll n;
ll tree[400005], a[100005];

void buildtree(ll id, ll l, ll r)
{
    if (l==r)
    {
        tree[id]=a[l];
        return;
    }
    ll mid=(l+r)/2;
    buildtree(id*2, l, mid);
    buildtree(id*2+1, mid+1, r);
    tree[id]=__gcd(tree[id*2], tree[id*2+1]);
}

ll getvalule(ll id, ll l, ll r, ll u, ll v)
{
    if (l>v || r<u) return 0;
    if (l>=u && r<=v) return tree[id];
    ll mid=(l+r)/2;
    return __gcd(getvalule(id*2, l, mid, u, v), getvalule(id*2+1, mid+1, r, u, v));
}

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>a[i];
    buildtree(1, 1, n);
    ll q; cin>>q;
    for (ll i=1; i<=q; i++)
    {
        ll x, y; cin>>x>>y;
        cout<<getvalule(1, 1, n, x, y)<<endl;
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