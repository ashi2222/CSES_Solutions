//Ashish Patel

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define forn(i,n) for(int i = 0; i <n;i++) 
#define invec(a,n)  vector<ll>a; for(int i =0 ; i < n ; i++){ll x ; cin>>x; a.push_back(x);}
#define outvec(a,n) for(int i =0 ; i < n ; i++){cout<<a[i]<<" ";}cout<<endl;
#define vec(a,n) vector<int>a(n,0);
#define yes cout<<"YES"<<endl;
#define srt(a) sort(a.begin() , a.end());
#define no cout<<"NO"<<endl;

const ll N = 1e6 + 3;
ll dp[N][2];


void solve(unordered_map<ll,vector<ll>>&adj , vector<pair<ll,ll>>&range , ll u , ll parent)
{
    if(u!=1 and adj[u].size() == 1)return;
    for(auto v : adj[u])
    {
        if(v!=parent)
        {
            solve(adj , range , v , u);
            dp[u][0] += max(abs(range[v].first - range[u].first) + dp[v][0]  , abs(range[v].second - range[u].first) + dp[v][1]); 
            dp[u][1] += max(abs(range[v].first - range[u].second) + dp[v][0]  , abs(range[v].second - range[u].second) + dp[v][1]); 
        }
    }
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<pair<ll,ll>>range(n+1);
        for(int i =1 ; i<=n ;i++)
        {
            ll l,r;
            cin>>l>>r;
            range[i] = {l,r};
        }
        // ab apn dekhte h 
        unordered_map<ll,vector<ll>>adj;
        for(int i = 0; i<n-1 ; i++)
        {
            ll u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // now i need ans 
        memset(dp , 0 , sizeof(dp));
        solve(adj , range , 1 , -1);

        ll tempans = max(dp[1][0] , dp[1][1]);
        cout<<tempans<<endl;


    }
    return 0;
}