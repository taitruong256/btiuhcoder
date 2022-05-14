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

void solve()
{
    ll n; cin>>n;
    vector<string> captian, woman, man, child;
    for (ll i=0; i<n; i++)
    {
        string s, t; cin>>s>>t;
        if (t=="captain") captian.push_back(s);
        if (t=="woman") woman.push_back(s);
        if (t=="man") man.push_back(s);
        if (t=="child") child.push_back(s);
    }
    for (auto it: captian) cout<<it<<endl;
    for (auto it: child) cout<<it<<endl;
    for (auto it: woman) cout<<it<<endl;
    for (auto it: man) cout<<it<<endl;
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