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
ll mod = 1e9 +  7 ;
ll power(int x , int n)
{
    if(n==0)return 1;
    if(n==1)return x;
    ll temp = power(x , n/2)%mod;
    if(n%2 == 0)
    {
        return (temp*temp)%mod;
    }
    else{
        return (((x*temp)%mod)*temp)%mod;
    }
}
int main() {
   
    {
        ll n;
        cin>>n;
        cout<<power(2, n)%mod<<endl;
    }
    return 0;
}