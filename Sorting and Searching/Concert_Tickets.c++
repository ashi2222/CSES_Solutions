//Ashish Patel

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define forn(i,n) for(int i = 0; i <n;i++) 
#define invec(a,n)  vector<ll>a; for(int i =0 ; i < n ; i++){ll x ; cin>>x; a.push_back(x);}
#define outvec(a,n) for(int i =0 ; i < n ; i++){cout<<a[i]<<" ";}cout<<endl;
#define vec(a,n) vector<int>a(n,0);
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;

int main() {
    {
        ll n,m;
        cin>>n>>m;
        invec(h,n)
        invec(t,m)
        map<ll,ll>mp;
        for(auto i : h){
            mp[i]++;
        }
        for(int i =0 ; i< m ; i++)
        {
            ll find = t[i];
            auto it = mp.upper_bound(find);
            if(it==mp.begin())
            {
                cout<<-1<<endl;
            }
            else{
                it--;
                cout<<it->first<<endl;
                it->second--;
                if(it->second == 0)
                {
                    mp.erase(it);
                }
                
                
            }
        }
    }
    return 0;
}