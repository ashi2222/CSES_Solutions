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
    vector<pair<ll,ll>>v(n);
    for(int i  =0 ; i < n ; i++)
    {
        cin>>v[i].first>>v[i].second;
    }
    //Maximum reward it can make 
    sort(v.begin(),v.end());
    ll time = 0;
    ll reward = 0;
    for(int i =0 ; i < n; i++)
    {
        time += v[i].first;
        reward += v[i].second - time;
    }
    cout<<reward<<endl;

    return 0;
}