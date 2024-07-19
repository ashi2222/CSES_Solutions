

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
    ll n,k;
    cin>>n>>k;
    invec(a,n)
    ll i =0 ;
    ll j =0 ;
    unordered_map<ll,ll>mp;
    ll dist =0 ;
    ll ans = 0;
    while(i<n)
    {
        
        if(mp.find(a[i])==mp.end() or mp[a[i]] == 0)
        dist++;
        mp[a[i]]++;
        while(dist>k)
        {
            mp[a[j]]--;
            if(mp[a[j]]==0)dist--;
            j++;
        }
        ans+=i-j+1;
        i++;

    }
    cout<<ans<<endl;
    return 0;
}