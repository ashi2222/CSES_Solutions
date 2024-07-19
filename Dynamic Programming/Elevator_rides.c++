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

ll solve(ll index , ll x , vector<ll>&w , ll n)
{
    if(index >= n)return 0;
    if(x==0)return 0;
    if(x<0)return INT_MAX;
    ll take = INT_MAX;
    if(x - w[index] >= 0)
    {
        take = solve(index + 1 , x-w[index] , w , n);
    }
    ll nontake = 1 + solve(index+1 , x ,w,n);
    return min(take,nontake);
}

int main() {
    ll n,x;
    cin>>n>>x;
    invec(w , n)
    vector<pair<ll,ll>>dp(1<<n , {1e9 , 1e9});
    dp[0] = {1 , 0};
    // smjhiyega 
    for(ll mask =1 ; mask < (1<<n) ; mask++ )
    {
        for(ll i = 0; i < n ;i++)
        {
            // ab aap dekhiye 
            if(mask&(1<<i))
            {
                pair<ll,ll>temp = dp[mask^(1<<i)];
                if(temp.second + w[i] <= x)
                {
                    temp.second += w[i];
                }
                else{
                    temp.second =  w[i];
                    temp.first++;
                }
                dp[mask] = min(dp[mask] , temp);
            }
        }
    }
    cout<<dp[(1<<n) - 1].first<<endl;
    return 0;
}                                                  