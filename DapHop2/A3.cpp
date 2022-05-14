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
ll max_tree[400005], min_tree[400005], a[100005];

void build_maxtree(ll id, ll l, ll r)
{
    if (l==r)
    {
        max_tree[id]=a[l];
        return;
    }
    ll mid=(l+r)/2;
    build_maxtree(id*2, l, mid);
    build_maxtree(id*2+1, mid+1, r);
    max_tree[id]=max(max_tree[id*2], max_tree[id*2+1]);
}

void update_maxtree(ll id, ll l, ll r, ll index, ll value)
{
    if (l>index || r<index) return;
    if (l==index && r==index)
    {
        max_tree[id]=value;
        return;
    }
    ll mid=(l+r)/2;
    update_maxtree(id*2, l, mid, index, value);
    update_maxtree(id*2+1, mid+1, r, index, value);
    max_tree[id]=max(max_tree[id*2], max_tree[id*2+1]);
}

ll get_maxtree(ll id, ll l, ll r, ll u, ll v)
{
    if (l>v || r<u) return 0;
    if (l>=u && r<=v) return max_tree[id];
    ll mid=(l+r)/2;
    return max(get_maxtree(id*2, l, mid, u, v), get_maxtree(id*2+1, mid+1, r, u, v));
}

void build_mintree(ll id, ll l, ll r)
{
    if (l==r)
    {
        min_tree[id]=a[l];
        return;
    }
    ll mid=(l+r)/2;
    build_mintree(id*2, l, mid);
    build_mintree(id*2+1, mid+1, r);
    min_tree[id]=min(min_tree[id*2], min_tree[id*2+1]);
}

void update_mintree(ll id, ll l, ll r, ll index, ll value)
{
    if (l>index || r<index) return;
    if (l==index && r==index)
    {
        min_tree[id]=value;
        return;
    }
    ll mid=(l+r)/2;
    update_mintree(id*2, l, mid, index, value);
    update_mintree(id*2+1, mid+1, r, index, value);
    min_tree[id]=min(min_tree[id*2], min_tree[id*2+1]);
}

ll get_mintree(ll id, ll l, ll r, ll u, ll v)
{
    if (l>v || r<u) return 1e9;
    if (l>=u && r<=v) return min_tree[id];
    ll mid=(l+r)/2;
    return min(get_mintree(id*2, l, mid, u, v), get_mintree(id*2+1, mid+1, r, u, v));
}

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>a[i];
    build_maxtree(1, 1, n);
    build_mintree(1, 1, n);
    ll q; cin>>q;
    for (ll i=1; i<=q; i++)
    {
        ll t, x, y; cin>>t>>x>>y;
        if (t==1)
        {
            update_maxtree(1, 1, n, x, a[y]);
            update_mintree(1, 1, n, x, a[y]);
            update_maxtree(1, 1, n, y, a[x]);
            update_mintree(1, 1, n, y, a[x]);
        }
        else 
        {
            if (get_maxtree(1, 1, n, x, y)-get_mintree(1, 1, n, x, y)==y-x) cout<<"YES\n";
            else cout<<"NO\n";
            cout<<get_maxtree(1, 1, n, x, y)<<" "<<get_mintree(1, 1, n, x, y)<<endl;
            // for (ll i=1; i<=4*n; i++) cout<<max_tree[i]<<" "; cout<<endl;
            // for (ll i=1; i<=4*n; i++) cout<<min_tree[i]<<" "; cout<<endl;
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