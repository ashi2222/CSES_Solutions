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
const int mod = 1e9+7;
bool check(int i , int j , int n , vector<vector<char>>&mat , vector<vector<int>>&visited)
{
    if(i<0 or i>=n or j<0 or j>=n or visited[i][j] == 1 or mat[i][j] == '*')return false;
    return true;
}
ll solve(int i , int j ,int n , vector<vector<char>>&mat , vector<vector<int>>&visited , vector<vector<int>>&dp)
{
    if(i==n-1 and j == n-1)
    {
        // ans = (ans+1)%mod;
        // return;
        return 1;
    }
    if(i>=n or j>=n)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    ll ans = 0;
    visited[i][j] = 1;
    if(check(i+1 , j , n , mat ,visited ))
    {
        ans = (ans + solve(i+1 , j , n  , mat , visited , dp))%mod;
    }
    if(check(i,j+1 , n , mat ,visited))
    {
        ans = (ans + solve(i , j+1 , n , mat , visited , dp))%mod;

    }
    visited[i][j] = 0;
    return dp[i][j] = ans;
}
int main() {
    ll n;
    cin>>n;
    vector<vector<char>>mat(n , vector<char>(n));
    for(int i =0 ; i < n ; i++)
    {
        for(int j = 0; j < n ; j++)
        {
            cin>>mat[i][j];
        }
    }
    if(mat[0][0]=='*' or mat[n-1][n-1]=='*'){
        cout<<0<<endl;
    }
    else{
        if(mat[n-1][n-1]=='*')return 0;
        vector<vector<int>>dp(n+1 , vector<int>(n+1 , -1));
        vector<vector<int>>visited(n , vector<int>(n , 0));
        // we need to start from 0 , 0 to reach n-1 , n-1 
        int ans =0 ;
        cout<<solve(0 , 0 , n ,  mat , visited , dp)<<endl;
    }
    //cout<<ans<<endl;
    return 0;
}