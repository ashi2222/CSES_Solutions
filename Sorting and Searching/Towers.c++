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
    vector<ll>srt;
    ll last = 0;
    srt.push_back(k[0]);
    for(int i =1 ; i< n ; i++)
    {
        auto it = upper_bound(srt.begin() , srt.end() , k[i]) ;
        if(it == srt.end())
        {
            //cout<<k[i]<<endl;
            srt.push_back(k[i]);
        }
        else{
            ll index = it - srt.begin();
            srt[index] = k[i];
        }
        
    }
    cout<<srt.size()<<endl;
    return 0;
}