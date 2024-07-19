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
    ll n,x;
    cin>>n;
    invec(a,n)
    unordered_map<ll,ll>mp;
    mp[0] = 1;
    ll sum =0 ;
    ll cnt =0;
    for(ll i =0 ; i < n ;i++)
    {
        sum+=a[i];
        if(mp.find(((sum)%n + n)%n)!=mp.end())
        {
            //cnt++;
            cnt+=mp[((sum)%n+n)%n];
        }
        mp[((sum%n)+n)%n]++;
    }
    cout<<cnt<<endl;
    return 0;

}