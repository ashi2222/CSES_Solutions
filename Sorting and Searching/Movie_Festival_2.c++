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
    vector<pair<ll,ll>>a(n);
    for(int i =0 ; i < n ;i++)
    {
        cin>>a[i].first>>a[i].second;
    }
    sort(a.begin(), a.end());
    multiset<ll>st;
    ll ans =0;
    for(int i =0 ; i < k ; i++)
    {
        ans++;
        st.insert(a[i].second);
    }
    for(int i = k ;i<n;i++)
    {
        auto maxi = st.rbegin();
        auto mini = st.begin();
        if(a[i].first >= *mini)
        {
            ans++;
            st.erase(st.find(*mini));
            st.insert(a[i].second);
        }
        else if(a[i].second < *maxi)
        {
            st.erase(st.find((*maxi)));
            st.insert(a[i].second);
        }
    }
    cout<<ans<<endl;
    return 0;
}