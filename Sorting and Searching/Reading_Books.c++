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
    invec(t,n)
    int j = n-1;
    sort(t.begin() , t.end());
    ll sum =0 ;
    for(int i =0 ; i<n-1 ; i++)
    {
        sum+=t[i];
    }
    if(sum < t[n-1])
    {
        sum += (t[n-1]-sum) ;
    }
    sum+=t[n-1];
    cout<<sum<<endl;
    return 0;
}