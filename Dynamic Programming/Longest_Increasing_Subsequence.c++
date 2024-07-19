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

ll solve(ll index , ll prev , vector<ll>&a , ll n , vector<ll>temp , vector<vector<ll>>&ans)
{
    if(index >= n)
    {
        ans.push_back(temp);
        return 0;
    }
    // ab aap dekhiye 
    ll take = 0;
    if(prev == -1 or a[index] > a[prev])
    {
        temp.push_back(a[index]);
        take = 1 + solve(index+1 , index , a , n , temp , ans);
        temp.pop_back();
    }
    ll nontake=  solve(index+1 , prev , a, n , temp , ans);
    return max(take , nontake);
    
}

ll solve2(vector<ll>&a)
{
    ll n= a.size();
    vector<vector<ll>>dp(n+1 , vector<ll>(n+1 , 0));
    for(ll i = n-1 ; i>= 0 ; i--)
    {
        for(ll prev = i-1 ; prev >= -1 ; prev--)
        {
            // ab smjhiye 
            ll take = 0;
            if(prev == -1 or a[i] > a[prev])
            {
                //cout<<a[i]<<" ";
                take = 1 + dp[i+1][i+1];
            }
            ll nontake = dp[i+1][prev+1];
            dp[i][prev+1] = max(take , nontake);
        }
    }
    return dp[0][0];
}
 ll solve3( ll n ,vector<ll>&nums)
    {
    //    vector<vector<ll>>dp(n+1 , vector<ll>(n+1 , 0));
        vector<ll>currR(n+1 , 0);
        vector<ll>next(n+1 , 0);
       for(ll curr = n-1 ; curr>=0 ; curr--)
       {
           for(ll prev = curr-1; prev>=-1 ;prev--)
           {
                ll include = 0 ;
                if(prev == -1 || nums[curr] > nums[prev])
                {
                    include = 1 + next[curr+1];
                }
                ll exclude = next[prev+1] ;
                currR[prev+1] =  max(include, exclude);
               
           }
           next = currR;
       }
       return next[0];

    }
int main() {
    
    {
        ll n;
        cin>>n ;
        invec(a , n)
        cout<<solve3(n,a)<<endl;
        //cout<<solve2(a)<<endl;
        // Now I want to print the longest increasing subsequence 
        // smjhiye 
        // vector<vector<ll>>ans;
        // vector<ll>temp;
        // ll i =0 ;
        // ll prev = -1;
        // ll res = solve( i , prev , a , n , temp , ans );
        // cout<<res<<endl;
        // for(auto i : ans)
        // {
        //     if(i.size() == res)
        //     {
        //         for(auto j : i)
        //         {
        //             cout<<j<<" ";
        //         }
        //         cout<<endl;
        //     }
        // }

        

    }
    return 0;
}