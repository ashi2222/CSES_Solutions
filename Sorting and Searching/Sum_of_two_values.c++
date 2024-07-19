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
    ll n,x;
    cin>>n>>x;
    invec(a,n)
    // here x is our target sum 
    map<ll,vector<ll>>mp;
    for(int i =0 ; i < n ; i++)
    {
        mp[a[i]].push_back(i+1);
    }
    bool flag = false;
    for(int i =0 ; i < n ;i++)
    {
        ll num = a[i];
        if(mp.find(x-num)!=mp.end())
        {
            if(x-num == num and mp[num].size()>1)
            {
                 cout<<mp[num][0]<<" "<<mp[num][1]<<endl;
                 flag = true;
                 break;
            }
            else if(x-num != num)
            {
                flag = true;
                cout<<mp[num][0]<<" "<<mp[x-num][0]<<endl;
                break;
            }
        }
    }
    if(flag==false)cout<<"IMPOSSIBLE"<<endl;
    return 0;
}