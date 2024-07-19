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
    
        ll n;
        cin>>n;
        if(n==1)cout<<1<<endl;
        else if(n<=3)
        {
            cout<<"NO SOLUTION"<<endl;
        }
        else if(n==4)
        {
            cout<<"2 4 1 3"<<endl;
        }
        else{
        vector<int>a(n);
        int count =1 ;
        for(int i =0 ; i < n ; i+=2)
        {
            a[i] = count++;
        }
        for(int i = 1 ; i< n ; i+=2)
        {
            a[i] = count++;
        }
        for(auto i : a)
        {
            cout<<i<<" ";
        }
        cout<<endl;
        }
    return 0;
}