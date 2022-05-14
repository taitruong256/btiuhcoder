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
ll n, m, ans=0;
bool danhdau[20];
ll nghiem[20];

void check()
{
    // for (ll i=1; i<=5; i++) cout<<nghiem[i]<<" "; cout<<endl;
    ll d=nghiem[2]-nghiem[1];
    if (d<0) return;
    for (ll i=3; i<=5; i++)
    {
        if (nghiem[i]-nghiem[i-1]!=d) return;
    }
    ans++;
    ans%=m;
}

void chinhhop_n_k(ll i)
{
    for (ll j=1; j<=n; j++) if (danhdau[j]==false)
    {
        nghiem[i]=j;
        danhdau[j]=true;
        if (i==5) check();
        else chinhhop_n_k(i+1);
        danhdau[j]=false;
    }
}


void solve()
{
    cin>>n>>m; 
    memset(danhdau, false, sizeof(danhdau));
    chinhhop_n_k(1);
    cout<<ans;
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