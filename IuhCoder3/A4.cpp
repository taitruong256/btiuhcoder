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
const ll mod=4022004;

void solve()
{
    ll n; cin>>n;
    if (n%3!=0)
    {
        cout<<0;
        return;
    }
    
    ll a=1;
    for (ll i=1; i<=n; i++) a=(a*i)%mod;
    ll b=0;
    for (ll i=1; i<=n/3; i++) if (__gcd(i, n)==1) ++b;
    ll c=0;
    for (ll i=1; i<=n-n/3; i++) if (__gcd(i, n)==1) ++c;
    cout<<(((a*b)%mod)*c)%mod;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}