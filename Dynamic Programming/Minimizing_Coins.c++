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
ll solve(vector<ll>&c , ll x , vector<ll>&dp)
{
    if(x==0)return 0;
    if(x<0)return INT_MAX;
    if(dp[x]!=-1)return dp[x];
    ll ans =INT_MAX;
    for(int i =0; i < c.size()  ; i++ )
    {
        ans = min(ans ,  1 + solve(c , x-c[i] ,dp));
    }
    return dp[x] = ans;
}
int main() {
    
    ll n,x;
    cin>>n>>x;
    invec(c,n)
    vector<ll>dp(x+1 , -1);
    ll ans = solve(c , x , dp);
    if(ans == INT_MAX)cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}