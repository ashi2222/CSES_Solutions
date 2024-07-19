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
    invec(k,n)
    map<ll,ll>mp;
    ll ans = 0;
    ll last =0 ;
    ll cap =0 ;
    for(int i =0 ; i < n ;i++)
    {
        if(mp.find(k[i])==mp.end())
        {
            mp[k[i]]=i;
            cap++;
             //cout<<k[i]<<" "<<mp[k[i]]<<" "<<cap<<endl;
        }
        else{
            last = max(last , mp[k[i]]);
            cap = i - last;
            mp[k[i]]=i;
            //cout<<"found "<<k[i]<<" "<<mp[k[i]]<<" "<<cap<<endl;
            
        }
        ans = max(ans , cap);
    }
    cout<<ans<<endl;
    return 0;
}