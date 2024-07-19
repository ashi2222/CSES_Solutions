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
        ll n;
        cin>>n;
        vector<ll>arrival;
        vector<ll>leaving;

        for(int i =0 ; i < n ; i++)
        {
            ll a,b;
            cin>>a>>b;
            arrival.push_back(a);
            leaving.push_back(b);
        }

        sort(arrival.begin(),arrival.end());
        sort(leaving.begin(),leaving.end());

        ll cnt =0;
        ll j =0 ;
        ll i =0;
        ll ans = 0;
        while(i<n and j<n)
        {
            if(arrival[i] < leaving[j])
            {
                cnt++;
                i++;
                ans = max(ans , cnt);
            }
            else{
                j++;
                cnt--;
            }
        }
        cout<<ans<<endl;






    }
    return 0;
}