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
    invec(a,n)
    stack<ll>st;
    st.push(-1);
    vector<int>ans(n);
    for(int i = 0 ;i < n ; i++)
    {
        while(st.top()!=-1 and a[st.top()]>=a[i])
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    for(int i =0 ; i < n ; i++)
    {
        cout<<ans[i]+1<<" ";
    }
    cout<<endl;

    return 0;
}