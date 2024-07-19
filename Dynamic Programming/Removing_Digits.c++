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

int main() {
    ll n;
    cin>>n;
    vector<ll>dp(n+1 , 1e9);
    dp[0]=0;
    for(int i =1 ; i <= n ; i++)
    {
        ll num = i;
        while(num)
        {
            ll temp = num%10;
            if(i-temp>=0)
                dp[i] = min(dp[i] ,1+ dp[i-temp]);
            num/=10;
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}