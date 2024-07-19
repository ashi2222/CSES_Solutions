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

ll solve(ll N, ll X, vector<ll> price, vector<ll> pages)
{
    vector<ll> dp(X + 1, 0);
    for (int i = 0; i < N; i++) {
        
        for (int C = X; C > 0; C--) {
            
            if (price[i] > C)
                continue;
            
            dp[C] = max(dp[C], pages[i] + dp[C - price[i]]);
        }
    }
    return dp[X];
}
int main() {
    ll n,x;
    cin>>n>>x;
    invec(h,n)
    invec(s,n)
    cout<<solve(n , x , h , s)<<endl;

    return 0;
}