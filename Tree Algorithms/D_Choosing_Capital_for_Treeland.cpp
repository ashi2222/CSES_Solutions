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
    
    // ll n;
    // cin>>n;
    // cout<<__popcount(n)<<endl;
    ll p,q,r;
    cin>>p>>q>>r;
    ll ans =0;
    ll xxor = p^q;
    while(r and xxor)
    {
        if((xxor &1) != (r&1))ans++;
        xxor>>=1;
        r>>=1;
    }
    if(r)
    {
        ans+= __popcount(r);
    }
    if(xxor)
    {
        ans+= __popcount(xxor);
    }

    cout<<ans<<endl;
    
    return 0;
}