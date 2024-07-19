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
ll mod = 1e9 + 7 ;
ll solve(ll n , vector<ll>&dp)
{
    if(n==0)return 1;
    if(n<0)return 0;
    if(dp[n]!=-1)return dp[n];
    ll ans =0 ;
    for(int i =1 ; i <= 6 ; i++)
    {
        ans = (ans+solve(n-i,dp)%mod)%mod;
    }
    return dp[n]=ans%mod;
}
int main() {
    ll n;
    cin>>n;
    vector<ll>dp(n+1 , -1);

    cout<<solve(n , dp)<<endl;
    return 0;
}