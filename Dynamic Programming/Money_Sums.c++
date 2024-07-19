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

// void solve(int index , int n , map<ll,ll>&mp , vector<ll>&a , ll sum)
// {
//     if(index == n)
//     {
//         //cout<<sum<<endl;
//         mp[sum]++;
//         return;
//     }
//     solve(index + 1 , n , mp , a , sum+a[index]);
//     solve(index + 1 ,  n , mp , a , sum);
// }
ll solve2(int index , int N , map<ll,ll>&mp , vector<ll>&coins)
{
    ll sum = accumulate(coins.begin(), coins.end(), 0LL);

    vector<vector<bool> > dp(N + 1,
                             vector<bool>(sum + 1, false));
    dp[0][0] = true;

    
    for (int i = 1; i <= N; i++) {
       
        for (int j = 0; j <= sum; j++) {
          
            dp[i][j] = dp[i - 1][j];
            if (j >= coins[i - 1]
                && dp[i - 1][j - coins[i - 1]]) {
                dp[i][j] = true;
            }
        }
    }

    
    vector<int> possibleSums;

    for (int j = 1; j <= sum; j++) {
        if (dp[N][j]) {
            possibleSums.push_back(j);
        }
    }

   
    cout << possibleSums.size() << endl;
    for (int i = 0; i < possibleSums.size(); i++)
        cout << possibleSums[i] << " ";
    cout << endl;

    return 0;

}
int main() {
    ll n;
    cin>>n;
    invec(a,n)
    ll sum =0 ;
    // i need to find all possible money sums 
    // that can be created using these coins 

    // // set<ll>st;
     map<ll,ll>mp;
    // // take or not take 
    // int index =0 ;
    // //solve(index , n , mp , a , sum);
    // if(mp[0] > 1)
    // {
    //     cout<<mp.size()<<endl;
    // }
    // else{
    //     cout<<mp.size()-1<<endl;
    // }

    // for(auto i : mp)
    // {
    //     if(i.first == 0 and i.second > 1)cout<<i.first<<" ";
    //     else if(i.first == 0)continue;
    //     else cout<<i.first<<" ";
    // }
    // cout<<endl;
    solve2(0 , n , mp , a);
    return 0;
}