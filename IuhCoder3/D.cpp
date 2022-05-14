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
const ll mod=1e9+7;

void solve()
{
    string s, t;
    ll m; 
    cin>>s>>t>>m;    
    ll giaithua[1100];
    giaithua[0]=1;
    for (ll i=1; i<1030; i++) giaithua[i]=(giaithua[i-1]*i)%mod;
    for (ll i=1; i<=100; i++) cout<<giaithua[i]<<endl;

    cout<<giaithua[s.size()]<<" "<<giaithua[t.size()]<<" "<<giaithua[m];
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