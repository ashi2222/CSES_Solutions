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
    invec(nums,n)
    ll curr =0 ; 
        ll ans = nums[0] ;
        for(int i  =0 ; i  < nums.size() ; i++)
        {
            curr += nums[i] ;
            ans = max(ans,  curr);
            if(curr < 0)curr= 0 ;
        }
    cout<<ans<<endl;
    return 0;
}