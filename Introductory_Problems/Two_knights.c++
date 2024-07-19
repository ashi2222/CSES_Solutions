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
vector<ll>dp(10001 , -1);
int main() {
    
    {
        ll n;
        cin>>n;
        dp[1] = 0;
        for(int i =1 ; i<= n ; i++)
        {
            if(dp[i]!=-1)cout<<dp[i]<<endl;
            else{
                ll ash = i*i;
                ll rj = i*i-1;
                // number of ways in which we can place two kinghts on i*i chessboard 

                ll kh =( ash * rj ) / 2 ;
                
                // how many ways they can attack 
                ll attack = 4 * (i-1)*(i-2);
                cout<<kh-attack<<endl;
                dp[i] = kh-attack;
                

            }
        }


    }
    return 0;
}