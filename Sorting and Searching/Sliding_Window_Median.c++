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

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <functional>
using namespace __gnu_pbds;

// PBDS MULTISET USING LESS_EQUAL
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
int main() {
    ll n,k;
    cin>>n>>k;
    invec(a,n)
    ordered_set st;
    for(int i =0 ; i < k ;i++)
    {
        st.insert(a[i]);
    }
    cout<<*st.find_by_order((k-1)/2)<<" ";
    for(int i = k ; i<n ; i++)
    {
        //cout<<st.order_of_key(a[i-k])<<" ";
        st.erase(st.find_by_order(st.order_of_key(a[i-k])));
        st.insert(a[i]);
        cout<<*st.find_by_order((k-1)/2)<<" ";
    }
    cout<<endl;

    return 0;
}