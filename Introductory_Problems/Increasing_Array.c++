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
    ll n;
    cin>>n;
    invec(a,n)
    ll count =0;
    for(int i =1 ; i < n ;i++)
    {
        if(a[i] >= a[i-1] )continue;
        count += (a[i-1] - a[i]);
        a[i] = a[i-1];
        
    }
    cout<<count<<endl;
    return 0;
}