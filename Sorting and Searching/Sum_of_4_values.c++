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
    vector<pair<ll,ll>>a(n);
    for(ll i = 0 ;i < n ; i++)
    {
        cin>>a[i].first;
        a[i].second = i+1;
    }
    sort(a.begin() , a.end());
    bool flag = false;
    for(ll i =0 ; i < n ; i++)
    {
        for(ll j = i+1 ; j < n ;j++)
        {
            ll k = j+1;
            ll l = n-1;
            
            while(k<l)
            {
                ll sum = a[i].first + a[j].first + a[k].first + a[l].first;
                if(sum == x){
                    cout<<a[i].second<<" "<<a[j].second <<" "<< a[k].second <<" "<< a[l].second <<endl;
                    flag = true;
                    break;
                }
                else if(sum>x)
                {
                    l--;
                }
                else{
                    k++;
                }
            }
            if(flag)break;

        }
        if(flag)break;
    }
    if(!flag)cout<<"IMPOSSIBLE"<<endl;
    return 0;
}