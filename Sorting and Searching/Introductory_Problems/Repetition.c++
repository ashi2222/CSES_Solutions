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
    string s ;
    cin>>s;
    ll n  = s.size();
    int maxi = 1;
    int count =1;
    for(int i =0 ;i < n-1 ; i++)
    {
        if(s[i] == s[i+1])
        {
            count++;
            maxi = max(maxi ,count);
        }
        else{
            count = 1;
        }
    }
    cout<<maxi<<endl;
    return 0;
}