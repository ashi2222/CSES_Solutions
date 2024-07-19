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
ll power(ll a, ll b)
{
    ll res = 1;
    while (b > 0) {
        // If b is an odd number, then
        // (a^b) = (a * (a^(b–1)/2)^2)
        if (b & 1) {
            res = (res * a);
        }

        // If b is an even number, then
        // (a^b) = ((a^2)^(b/2))
        a = (a * a);
        b >>= 1;
    }
    return res;
}
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll digit = 1;
        ll base = 9;
        while(n - digit*base > 0)
        {
            n-=(digit*base);
            base*=10;
            digit++;
        }
        ll place = n%digit;
        ll num = power(10 , (digit-1)) + (n-1)/digit;
        if(place!=0)
        {
            num /= power(10 , (digit - place));
        }
        cout<<num%10<<endl;
        


    }
    return 0;
}