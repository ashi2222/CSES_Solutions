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


ll solve(int i , int j , string& a , string& b)
{
    if(i==a.size() and j == b.size())return 0;
    if(i==a.size())return (b.size() - j);
    if(j==b.size())return (a.size() - i);
    //ll ans =INT_MAX ;
    if(a[i] == b[j])
        return solve(i+1 , j+1 , a, b);
    else 
    {
        ll edit = 1 + solve(i+1 , j + 1 , a, b);
        ll add = 1 + solve(i+1 , j , a, b);
        ll remove = 1 + solve(i , j+1 , a, b);
        return min({edit , add , remove});
    }
}
ll solve(string a , string b)
{
    ll n = a.size();
    ll m = b.size();
    vector<vector<ll>>dp(n+1 , vector<ll>(m  + 1 , 0 ));
    dp[n][m] = 0;
    for(int i =0 ; i <= n ; i++)
    {
        dp[i][m] = n-i;
    }
    for(int j = 0 ; j<= m ; j++)
    {
        dp[n][j] = m-j;
    }
    for(int i = n-1 ; i>=0 ; i--)
    {
        for(int j = m-1 ; j>=0 ; j--)
        {
            if(a[i] == b[j])
            {
                dp[i][j] = dp[i+1][j+1];
            }
            else{
                dp[i][j] = min({1 + dp[i+1][j+1] , 1 + dp[i+1][j] , 1 + dp[i][j+1]});
            }
        }
    }
    return dp[0][0];
}
int main() {
   
    {
        string a;
        cin>>a;
        string b;
        cin>>b;
        int i = 0;
        int j= 0;
        cout<<solve(a,b)<<endl;
        //cout<< solve(i,j,a,b)<<endl;
    }
    return 0;
}