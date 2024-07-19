//Ashish Patel

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define forn(i,n) for(int i = 0; i <n;i++) 
#define invec(a,n)  vector<int>a; for(int i =0 ; i < n ; i++){long long int x ; cin>>x; a.push_back(x);}
#define outvec(a,n) for(int i =0 ; i < n ; i++){cout<<a[i]<<" ";}cout<<endl;
#define vec(a,n) vector<int>a(n,0);
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
void solve(ll n , vector<ll>&ans)
{
    if(n==1)
    {
        ans.push_back(n);
        return;
    }
    ans.push_back(n);
    if(n%2 == 0)
    {
        solve(n/2 , ans);
    }
    else{
        solve(n*3 + 1 , ans);
    }
}
int main() {
    ll n;
    cin>>n;
    vector<ll>ans;
    solve(n , ans);
    for(auto i : ans)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}