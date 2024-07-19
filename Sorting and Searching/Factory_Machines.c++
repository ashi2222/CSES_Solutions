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

bool check(vector<ll>&k , ll mid , ll target)
{
    // ab aap smjhiye 
    ll ans =0 ;
    for(int i =0 ; i < k.size() ; i++)
    {
        ans += mid/k[i];
        if(ans >= target)return true;
    }
    return false;
}
int main() {
    ll n,t;
    cin>>n>>t;
    invec(k,n)
    sort(k.begin() , k.end());
    ll high = k[0]*t;
    //cout<<high<<endl;
    ll low = 0 ;
    ll ans ;
    while(low <= high)
    {
        ll mid = (low + (high - low)/2);
        //cout<<mid<<endl;
        if(check(k , mid , t))
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