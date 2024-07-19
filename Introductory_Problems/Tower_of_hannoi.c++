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
int solve(int n)
{
    if(n==1)return 1;
    return 2*solve(n-1)+1;
}
void solve2(int i , int j , int k  , int n)
{
    // ab aap dekhiye toh 
    if(n==1)
    {
        cout<<i<<" "<<k<<endl;
        return;
    }
    solve2(i,k,j,n-1);
    cout<<i<<" "<<k<<endl;
    solve2(j,i,k ,n-1);
}
int main() {
    
    {
        ll n;
        cin>>n;
        // no of moves 
        int ans = solve(n);
        cout<<ans<<endl;
        solve2(1,2,3,n);
    }
    return 0;
}