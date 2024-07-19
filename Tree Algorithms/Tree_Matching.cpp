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

ll dp[200001][2];

// Maxumum no. of edges 
ll solve(ll vertex , ll include , unordered_map<ll,vector<ll>>&adj , ll parent )
{
    if(dp[vertex][include]!=-1)return dp[vertex][include];
    // ab smjhiyega 
    if(include==1)
    {
        ll ans =0 ;
        for(auto v : adj[vertex])
        {
            if(v!=parent)
            {
                ans += solve(v , 1 , adj , vertex);
            }
        }
        ll res = 0;
        for(auto v : adj[vertex])
        {
            if(v!=parent)
            {
                res = max(res , ans - dp[v][1] + solve(v , 0 , adj , vertex));
            }
        }
        dp[vertex][include] = res;
        return res;
    }
    else{
        ll ans =0 ;
        for(auto v : adj[vertex])
        {
            if(v!=parent)
            {
                ans += solve(v , 1 , adj , vertex);
            }
        }
        dp[vertex][include] = ans;
        return ans;
    }
}
int main() {
    

    ll n;
    cin>>n;

    unordered_map<ll,vector<ll>>adj;

    for(int i =0 ; i < n-1 ; i++)
    {
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // ab smjhiyega 
    memset(dp , -1 , sizeof(dp));
    //solve(0 ,1 , -1  , adj);
    cout<<max(solve(1,0,adj,-1) , solve(1,1,adj,-1))<<endl;

    return 0;
}