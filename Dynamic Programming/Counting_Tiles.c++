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

const int mod = 1e9 + 7 ;

void generate(ll row , ll newmask , ll currmask , vector<ll>&next_masks , ll n , ll m)
{
    if(row == n)
    {
        next_masks.push_back(newmask);
        return;
    }

    // ab aap smjhiyega 
    if((row+1 < n) and (((1<<row)  & (currmask)) ==0) and ((1<<(row+1)) & currmask) == 0)
    {
        generate(row+2 , newmask , currmask , next_masks , n , m );
    }
    if(((1<<row) & currmask) == 0)
    {
        generate(row + 1 , newmask + (1<<row) , currmask , next_masks , n , m );
    }
    if(((1<<row) & (currmask)) != 0)
    {
        generate(row + 1 , newmask , currmask , next_masks , n , m);
    }

}
ll solve(ll col , ll mask , ll n ,ll m ,  vector<vector<ll>>&dp)
{
    if(col == m)
    {
        if(mask == 0)return 1;
        return 0;
    }
    if(dp[col][mask]!=-1)return dp[col][mask];
    // ab aap dakiyega 
    vector<ll>next_masks ;
    generate(0 , 0 , mask , next_masks , n , m);

    ll ans =0 ;
    for(auto x : next_masks)
    {
        ans  = (ans + solve(col+1 , x , n ,m , dp)%mod)%mod; 
    }
    return dp[col][mask] = ans;
}
int main() {
    ll n,m;
    cin>>n>>m;
    // I need to count the ways for filling the grid using 1*2 and 2*1 tiles 
    // solving by bit mask 
    vector<vector<ll>>dp(m+1 , vector<ll>(1<<n+1 , -1));
    ll mask  = 0;
    ll column = 0 ;
    cout<<solve(column , mask , n , m , dp)<<endl;
    return 0;
}


