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
    ll n,a,b;
    cin>>n>>a>>b;
    invec(k,n)
    // Maximum Subarray Sum of contiguous subarray with length between a&b ]
    multiset<ll>st;
    vector<ll>prefix(n+1 ,0 );
    for(int i = 1 ; i<= n ;i++)
    {
        prefix[i] = prefix[i-1] + k[i-1];
    }
    for(int i =a ; i<= b ;i++)
    {
        st.insert(prefix[i]);
    }
    ll ans = *st.rbegin();
    for(ll i =1 ; i<= n-a; i++)
    {
        st.erase(prefix[i+a-1]);
        st.insert(prefix[min(i+b , n)]);
        ans = max(ans , *st.rbegin()-prefix[i]);
    }
    cout<<ans<<endl;


    return 0;
}