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
    
    {
        ll n;
        cin>>n;
        ll sum = (n*(n+1))/2;
        if(sum%2 != 0)
        {
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
            ll find = sum/2 ;
            ll count = n;
            ll sum = 0;
            vector<int>visited(count , 0);
            vector<int>one;
            while(sum <= find){
                sum+=(count);
                one.push_back(count);
                visited[count] = 1;
                count--;
            }
            one.pop_back();
            visited[count+1] = 0;
            sum-=(count+1);
            if(find-sum > 0){   
                one.push_back(find - sum);
            }
            vector<int>second;
            visited[find - sum] =  1;
            for(int i =0 ; i< n ; i++)
            {
                if(visited[i+1] == 0)
                {
                    second.push_back(i+1);
                }
            }
            cout<<one.size()<<endl;
            for(auto i : one)
            {
                cout<<i<<" ";
            }
            cout<<endl;
            cout<<second.size()<<endl;
            for(auto i:second)
            {
                cout<<i<<" ";
            }
            cout<<endl;
        }


    }
    return 0;
}