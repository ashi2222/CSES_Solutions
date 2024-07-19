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
    int t;
    cin>>t;
    while(t--)
    {
        ll y,x;
        cin>>y>>x;
        if(x >y)
        {
            if(x%2 !=0)
            {
                ll ashu = x*x;
                ll jadu = ashu - y + 1;
                cout<<jadu<<endl;
            }
            else{
                ll ashu = (x-1)*(x-1) + 1;
                ll jadu = ashu + y - 1;
                cout<<jadu<<endl;
            }
        }
        else
        {
            if(y%2 ==0)
            {
                ll ashu = y*y;
                ll jadu = ashu - x + 1;
                cout<<jadu<<endl;
            }
            else{
                ll ashu = (y-1)*(y-1) + 1;
                ll jadu = ashu + x - 1;
                cout<<jadu<<endl;
            }
        }
    }
    return 0;
}