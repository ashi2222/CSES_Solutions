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

ll solve(int index , vector<ll>&p , int n , ll sum1 , ll sum2)
{
    if(index == n)
    {
        return abs(sum1 - sum2);
    }
    ll take = solve(index + 1 , p , n , sum1 + p[index] , sum2);
    ll nontake = solve(index +1 , p, n , sum1 , sum2 + p[index]);
    return min(take , nontake);
}

int main() {
    {
        ll n;
        cin>>n;
        vector<ll>p(n);
        for(ll i =0 ; i < n ; i++)
        {
            cin>>p[i];
        }
        cout<<solve(0 , p , n , 0 , 0)<<endl;
    }
    return 0;
}