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
        ll n,x;
        cin>>n>>x;
        invec(p,n)
        sort(p.begin() , p.end());
        int i =0 ;
        int j = n-1;
        ll count =0 ;
        while(i<=j)
        {
            if(p[i]+p[j] <=x )
            {
                count++;
                i++;
                j--;
            }
            else{
                j--;
                count++;
            }
        }
        cout<<count<<endl;

    }
    return 0;
}