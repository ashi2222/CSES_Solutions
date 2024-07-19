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


void dfs(vector<ll>&ans , unordered_map<ll,vector<ll>>&adj , ll u ,ll p)
{
    // smjhiyega 
    //cout<<"called"<<endl;
    if(u!=1 and adj[u].size() == 1)
    {
        ans[u] = 0;
        //cout<<u<<endl;
        return;
    }
    for(auto i : adj[u])
    {
        if(i!=p)
        {
            dfs(ans , adj ,  i , u);
            ans[u] += ans[i]; 
            ans[u]++;
        }
    }
    return;
}
int main() {
    
    ll n;
    cin>>n;
    unordered_map<ll,vector<ll>>adj;
    for(int i = 2 ; i<=n ; i++)
    {
        ll x;
        cin>>x;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }
    // So I have maintained the array 
    vector<ll>ans(n+1);
    dfs(ans , adj , 1 , -1);
    //cout<<ans.size()<<endl;
    for(int i = 1 ; i<=n; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}