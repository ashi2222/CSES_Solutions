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
ll dp[20][10][2][2];
//ll dp2[20][10][2][2];
ll solve(string number , ll n, ll x , ll leading_zeroes , ll tight)
{
    // smjhiye 
    if(n==0)return 1;
    if(x!=-1 and dp[n][x][leading_zeroes][tight]!=-1)return dp[n][x][leading_zeroes][tight];
    ll lb = 0;
    ll ub = tight ? number[number.size() - n] -'0' : 9 ;
    ll ans = 0;
    for(ll i = lb ; i<= ub ; i++)
    {
        if(i==x and leading_zeroes==0)continue;
        ans += solve(number , n-1 ,i , (leading_zeroes & (i==0)) , (tight & (i==ub))  );
    }
    //return ans;
    return dp[n][x][leading_zeroes][tight] = ans;
}
int main() {
    
    ll a,b;
    cin>>a>>b;

    string A = to_string(a-1);
    string B = to_string(b);
    memset(dp , -1 , sizeof dp );
    
    // vector<vector<vector<vector<ll>>>>dp1(20 , vector<vector<vector<ll>>>(10 , vector<vector<ll>>(2 , vector<ll>(2 , -1))));
    // vector<vector<vector<vector<ll>>>>dp2(20 , vector<vector<vector<ll>>>(10 , vector<vector<ll>>(2 , vector<ll>(2 , -1))));
    ll ans1 = solve(A , A.size() , -1 , 1 , 1 );
    memset(dp , -1 , sizeof dp );
    ll ans2 = solve(B , B.size() , -1 , 1 , 1 );
    cout<<ans2-ans1<<endl;
    return 0;
}

