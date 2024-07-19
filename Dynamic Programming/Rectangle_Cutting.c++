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

ll solve(ll a, ll b)
{
    if(a<0 or b<0)return INT_MAX;
    if(a==b)return 0;
    
    // partitioning the rectangle 
    ll ans =INT_MAX ;
    // partiotion over the horizontal line 
    for(int j = 1 ; j< b; j++)
    {
        ans = min(ans , 1 + solve(a,j) + solve(a,b-j));
    }
    for(int i = 1 ; i < a ; i++)
    {
        ans = min(ans , 1 + solve(i , b) + solve(a-i , b));
    }
    return ans;
}
ll solve2(ll a, ll b)
{
    vector<vector<int> > dp(a + 1, vector<int>(b + 1, 1e9));
    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
            // If the rectangle is already a square, then 0
            // cuts are required
            if (i == j) {
                dp[i][j] = 0;
            }
            else {
                for (int k = 1; k < j; k++) {
                    dp[i][j]
                        = min(dp[i][j],
                              dp[i][k] + dp[i][j - k] + 1);
                }
               
                for (int k = 1; k < i; k++) {
                    dp[i][j]
                        = min(dp[i][j],
                              dp[k][j] + dp[i - k][j] + 1);
                }
            }
        }
    }
    return dp[a][b];
}
int main() {
    
    {

        ll a,b;
        cin>>a>>b;
        cout<<solve2(a,b)<<endl;

    }
    return 0;
}