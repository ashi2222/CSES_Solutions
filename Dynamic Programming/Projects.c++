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
    vector<vector<ll>>mat(n, vector<ll>(3));
    for(ll i =0 ; i< n ; i++)
    {
        ll start , end , reward;
        cin>>start>>end>>reward;
        mat[i][0] = end;
        mat[i][1] = start;
        mat[i][2] = reward;
    }
    sort(mat.begin() , mat.end());
    //cout<<endl;
    // for(auto i : mat)

    // {
    //     cout<<i[0]<<" ";
    // }
    // cout<<endl;
    // set<ll>st;
    vector<ll>endpoint;
    vector<ll>dp(n+1 , 0);
    for(ll i =1 ; i<= n ; i++)
    {
        ll take = 0 ;
        ll j = lower_bound(endpoint.begin() , endpoint.end() , mat[i-1][1]) - endpoint.begin();
        take = mat[i-1][2] + dp[j];
        //cout<<j-1<<" "<<take<<" "<<endl;
        ll nontake = dp[i-1];
        endpoint.push_back(mat[i-1][0]);
        dp[i] = max(take , nontake);
    }
    cout<<dp[n]<<endl;
    return 0;
}