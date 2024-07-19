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
    unordered_map<ll,vector<ll>>mp;
    for(int i =0 ; i < n ;i++)
    {
        mp[a[i]].push_back(i+1);
    }
    sort(a.begin() ,a.end());
    bool flag = false;
    for(int i =0 ; i< n ; i++)
    {
        int j =i+1;
        int k = n-1;
        
        while(j<k){
            ll sum = (a[i] + a[j] + a[k]);
            //cout<<sum<<endl;
            if(x == sum )
            {
                if(a[i]==a[j] and a[j]==a[k])
                {
                    cout<<mp[a[i]][0]<<" "<<mp[a[i]][1]<<" "<<mp[a[i]][2]<<endl;
                }
                else if(a[i]==a[j])
                {
                    cout<<mp[a[j]][0]<<" "<<mp[a[j]][1]<<" "<<mp[a[k]][0]<<endl;
                }
                else if(a[i]==a[k])
                {
                    cout<<mp[a[i]][0]<<" "<<mp[a[i]][1]<<" "<<mp[a[j]][0]<<endl;
                }
                else if(a[j]==a[k])
                {
                    cout<<mp[a[j]][0]<<" "<<mp[a[j]][1]<<" "<<mp[a[i]][0]<<endl;
                }
                else{
                    cout<<mp[a[i]][0]<<" "<<mp[a[j]][0]<<" "<<mp[a[k]][0]<<endl;
                }
                flag = true;
                break;
            }
            else if(x<sum){
                k--;
            }
            else{
                j++;
            }
        }
        if(flag==true)
        {
            break;
        }
    }
    if(flag==false){
        cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}