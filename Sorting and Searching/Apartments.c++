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
        ll n,m,k;
        cin>>n>>m>>k;
        invec(a,n)
        invec(b,m)
        sort(a.begin()  , a.end());
        sort(b.begin() , b.end());
        int j =0 ;
        ll cnt =0 ;
        for(int i =0 ; i < n ;i++)
        {
            while((a[i] - b[j]) > k and j<m)
            {
                j++;
            }
            if(j<m and abs(a[i]-b[j]) <= k)
            {
                cnt++;
                j++;
            }
            if(j>=m)break;
        }
        cout<<cnt<<endl;



    }
    return 0;
}