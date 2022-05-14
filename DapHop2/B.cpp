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
    stack<string> st;
    map<string, ll> cnt; 
    for (ll i=0; i<n; i++)
    {
        string t; cin>>t;
        st.push(t);
    }
    vector<string> ans;
    while (!st.empty())
    {
        if (cnt[st.top()]==0) 
        {
            ans.push_back(st.top());
            ++cnt[st.top()];
        }
        st.pop();
    }
    cout<<ans.size()<<endl;
    for (auto it: ans) cout<<it<<endl;
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