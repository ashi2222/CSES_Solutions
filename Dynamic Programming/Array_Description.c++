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

const ll mod = 1e9 + 7 ;

int main() {
    ll n,m;
    cin>>n>>m;
    invec(c,n)
    // Now we need to initialize an array 
    vector<vector<ll>>dp(n+1 , vector<ll>(m+2 , 0));
    if(c[0] == 0)
    {
        for(ll j=1 ; j<=m ; j++)
        {
            dp[0][j] = 1;
        }
    }
    else 
    {
        dp[0][c[0]]=1;
    }
    for(ll i =1 ; i< n ;i++)
    {
        if(c[i]==0)
        {
            for(ll j = 1 ; j<= m ; j++)
            {
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1])%mod;
            }
        }
        else{
            dp[i][c[i]] = (dp[i-1][c[i]-1] + dp[i-1][c[i]+1] + dp[i-1][c[i]])%mod;
        }
    }
    ll ans =0 ;
    for(ll j = 1 ; j<= m ; j++)
    {
        ans = (ans + dp[n-1][j])%mod;
    }
    cout<<ans<<endl;
    return 0;
}