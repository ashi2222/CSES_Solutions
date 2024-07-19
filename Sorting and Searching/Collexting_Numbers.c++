//Ashish Patel

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define forn(i,n) for(int i = 0; i <n;i++) 
#define invec(a,n)  vector<ll>a; for(int i =0 ; i < n ; i++){ll x ; cin>>x; a.push_back(x);}
#define outvec(a,n) for(int i =0 ; i < n ; i++){cout<<a[i]<<" ";}cout<<endl;
#define vec(a,n) vector<ll>a(n);
#define yes cout<<"YES"<<endl;
#define srt(a) sort(a.begin() , a.end());
#define no cout<<"NO"<<endl;

int main() {
    ll n;
    cin>>n;
    vec(a,n)
    vector<int>pos(n+1 ,0 );
    forn(i,n){
        cin>>a[i];
        pos[a[i]]=i+1;
    }
    int cnt = 1;
    for(int i = 1 ; i < n ; i++)
    {
        if(pos[i] > pos[i+1])cnt++;
    }
    cout<<cnt<<endl;
    
    
    return 0;
}