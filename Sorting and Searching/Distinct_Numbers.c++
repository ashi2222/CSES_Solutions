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
        vector<ll>a(n);
        for(int i =0 ; i < n ; i++)
        {
            cin>>a[i];
        }
        map<ll,ll>mp;
        for(auto i : a)
        {
            mp[i]++;
        }
        cout<<mp.size()<<endl;
    }
    return 0;
}