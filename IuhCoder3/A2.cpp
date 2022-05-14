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
const ll mod=4022004;

void solve()
{
    ll giaithua[500005];
    giaithua[0]=1;
    for (ll i=1; i<500001; i++) giaithua[i]=(giaithua[i-1]*i)%mod;
    ll n; cin>>n;
    if (n%3!=0) cout<<0;
    else cout<<giaithua[n]/((giaithua[n/3]*giaithua[n-n/3]));
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