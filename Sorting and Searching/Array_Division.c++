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
bool check(vector<ll>&a , ll mid , ll k )
{
    ll sum =0 ;
    ll cnt =1;
    ll i =0 ;
    while(i<a.size())
    {
        sum+=a[i];
        
        if(sum > mid)
        {
            cnt++;
            sum = a[i] ;
        }
        if(cnt >k or a[i]>mid)return false;
        
        i++;
    }
    return cnt<=k;;
}
int main() {
    ll n,k;
    cin>>n>>k;
    // divide the subarray so that the maximum sum in a subarray is as small as possible 
    ll high =0;
    invec(a,n)
    for(auto i : a)
    {
        high +=i ;
    }
    ll low =0;
    ll ans = 0;
    while(low <= high)
    {
        // ab aap dekhiye 
        ll mid = (low + (high-low)/2);
        if(check( a, mid , k))
        {
            ans = mid ;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}