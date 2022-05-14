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
    ll a[n+5];
    set<ll> st;
    for (ll i=0; i<n; i++)
    {
        cin>>a[i];
        st.insert(a[i]);
    }
    sort(a, a+n);

    ll luot=0;
    while (true)
    {
        if (st.size()==1) break; 
        ll x=*st.begin();
        ll y=*st.upper_bound(x);
        while (y<=a[n-1] && (st.find(y-x)!=st.end() || st.find((y-x)/2)!=st.end() ||st.find((y-x)*2)!=st.end()))
        {
            y=*st.upper_bound(y);
        }
        if (y>a[n-1]) break;
        st.erase(x);
        st.erase(y);
        st.insert(y-x);
        luot++;
        // for (auto it: st) cout<<it<<" "; cout<<endl;
    }
    if (luot%2==1) cout<<"BINH";
    else cout<<"AN";
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