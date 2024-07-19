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

int main() {
    {
        ll n;
        cin>>n;
        invec(a,n-1);
        ll sum =0 ;
        for(auto i : a)
        {
            sum+=i;
        }
        ll g = (n*(n+1))/2;
        cout<<g-sum<<endl;
    }
    return 0;
}