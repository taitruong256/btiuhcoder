/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
ll n, m, a[100005], maxtree[400005], mintree[400005];

void build(ll id, ll l, ll r, ll tree[], ll type)
{
    if (l==r)
    {
        tree[id]=a[l];
        return;
    }
    ll mid=(l+r)/2;
    build(id*2, l, mid, tree, type);
    build(id*2+1, mid+1, r, tree, type);
    if (type==1) tree[id]=max(tree[id*2], tree[id*2+1]);
    else tree[id]=min(tree[id*2], tree[id*2+1]);
}

void update(ll id, ll l, ll r, ll tree[], ll index, ll value, ll type)
{
    if (r<index || l>index) return;
    if (l==index && r==index)
    {
        tree[id]=value;
        return;
    }
    ll mid=(l+r)/2;
    update(id*2, l, mid, tree, index, value, type);
    update(id*2+1, mid+1, r, tree, index, value, type);
    if (type==1) tree[id]=max(tree[id*2], tree[id*2+1]);
    else tree[id]=min(tree[id*2], tree[id*2+1]);
}

ll getvalue(ll id, ll l, ll r, ll tree[], ll index, ll value, ll type)
{
    if (r<index || l>index) return;
    if (l==index && r==index)
    {
        tree[id]=value;
        return;
    }
    ll mid=(l+r)/2;
    update(id*2, l, mid, tree, index, value, type);
    update(id*2+1, mid+1, r, tree, index, value, type);
    if (type==1) tree[id]=max(tree[id*2], tree[id*2+1]);
    else tree[id]=min(tree[id*2], tree[id*2+1]);
}

void solve()
{
    cin>>n;
    for (ll i=1 ;i<=n; i++) cin>>a[i];
    build(1, 1, n, maxtree, 1);
    build(1, 1, n, mintree, -1);
    for (ll i=1; i<=n; i++) cout<<maxtree[i]<<" "; cout<<endl;
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