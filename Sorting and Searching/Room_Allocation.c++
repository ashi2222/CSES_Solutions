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
    vector<pair<pair<ll,ll> , ll>>v(n);
    for(ll i =0 ; i < n ; i++)
    {
        cin>>v[i].first.first>>v[i].first.second;
        v[i].second = i;
    }
    sort(v.begin() , v.end());
    priority_queue<pair<pair<ll,ll>,ll> , vector<pair<pair<ll,ll>,ll>> , greater<pair<pair<ll,ll>,ll>>>pq;
    // ab aap dekhiye 
    vector<ll>ans(n);
    ll room = 0 ;
    
    for(ll i = 0; i  < n ; i++)
    {
        if(!pq.empty() and pq.top().first.first < v[i].first.first)
        {
            ll allocroom = pq.top().second;
            pq.pop();
            ans[v[i].second] = allocroom;
            pq.push({{v[i].first.second , v[i].first.first} , allocroom});
        }
        else{
            room++;
            pq.push({{v[i].first.second ,v[i].first.first},room});
            ans[v[i].second] = room;
        }
    }
    cout<<pq.size()<<endl;
    for(ll i =0 ; i < n ; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;


    return 0;
}