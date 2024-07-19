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
 
struct ranges{
    ll l , r, in;
    bool operator < (const ranges&other)
    {
        if(l==other.l)
        {
            return r > other.r;
        }
        return l < other.l;
    }
};
int main() {
     
 
    ll n;
    cin>>n;
    vector<ranges>range(n);
    for(ll i = 0; i < n ; i++)
    {
        cin>>range[i].l;
        cin>>range[i].r;
        range[i].in = i;
    } 
 
    // so we inserted it into a range 
    sort(range.begin() , range.end());
    // mene sort kr liye according to the rules 
    // now 
    vector<ll>contains(n);
    vector<ll>contained(n);
    contains[range[n-1].in] = 0;
    ll minend = range[n-1].r;
 
    for(int i =n-2 ; i>=0 ; i--)
    {
        if(range[i].r >= minend)
        {
            contains[range[i].in] = 1;
        }
        minend = min(minend , range[i].r);
    }
    contained[range[0].in] = 0 ; 
    ll maxend  = range[0].r;
    for(ll i =1 ; i< n ; i++)
    {
        if(range[i].r <= maxend)
        {
            contained[range[i].in] = 1;
        }
        maxend = max(maxend , range[i].r);
    }
    for(int i = 0; i < n ; i++)
    {
        cout<<contains[i]<<" ";
    }
    cout<<endl;
    for(int j =0 ; j < n ;j++)
    {
        cout<<contained[j]<<" ";
    }
    cout<<endl;
    return 0;
}