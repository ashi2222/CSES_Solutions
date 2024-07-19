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
const int mod = 1e9  +7 ;


int main() {
    ll n,x;
    cin>>n>>x;
    invec(c,n)
    ll ans =0 ;
    vector<ll>dp(1e6 +  5 ,0);
    // for(ll i = 0; i < n ; i++)
    // {
    //     dp[i][0] = 1;
    // }
    sort(c.begin(),c.end());
    dp[0]=1;
    for(ll i = 0 ; i<n ; i++)
    {
        for(ll sum = 1 ; sum <= x ; sum++)
        {
            if(sum - c[i]>=0)dp[sum]=(dp[sum]+dp[sum-c[i]])%mod;
            dp[sum]%=mod;
       }
    }
    cout <<dp[x]<<endl;
    // No . of distinct ways to calculate the money x 
    // since we need to make distinct we will start with the first 
    return 0;
}