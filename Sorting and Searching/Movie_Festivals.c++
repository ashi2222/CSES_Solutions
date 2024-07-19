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
    vector<pair<int,int>>vec;
    for(int i = 0; i < n ;i++)
    {
        ll a,b;
        cin>>a>>b;
        vec.push_back({b,a});
    }
    sort(vec.begin(),vec.end());
    int endtime = 0;
    ll cnt =0;
    for(int i =0 ; i < n ;i++)
    {
        if(vec[i].second >= endtime)
        {
            cnt++;
            endtime = vec[i].first;
        }
    }
    cout<<cnt<<endl;
    return 0;
}