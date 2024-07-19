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
#define MOD 1000000007

 vector<vector<int>> dp(1e6 + 1, vector<int>(2));
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
       dp[n][0] = 1;
        dp[n][1] = 1;
        for(int i = n - 1; i >= 0; i--){
            dp[i][0] = (2LL * dp[i+1][0] + dp[i+1][1]) % MOD;
            dp[i][1] = (4LL * dp[i+1][1] + dp[i+1][0]) % MOD;
        }
        
        // final subproblem
        cout << (dp[1][0] + dp[1][1]) % MOD << endl;
    }
    return 0;
}