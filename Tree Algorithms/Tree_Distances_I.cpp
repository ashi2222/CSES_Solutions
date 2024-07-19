//Ashish Patel

#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define pb push_back
#define forn(i,n) for(int i = 0; i <n;i++) 
#define invec(a,n)  vector<ll>a; for(int i =0 ; i < n ; i++){ll x ; cin>>x; a.push_back(x);}
#define outvec(a,n) for(int i =0 ; i < n ; i++){cout<<a[i]<<" ";}cout<<endl;
#define vec(a,n) vector<int>a(n,0);
#define yes cout<<"YES"<<endl;
#define srt(a) sort(a.begin() , a.end());
#define no cout<<"NO"<<endl;

unordered_map<int,vector<int>>adj;
int depth[200001];
int ans[200001];

void eval_depth(int src , int parent)
{
    int height = 0;
    for(auto i : adj[src])
    {
        if(i!=parent)
        {
            eval_depth(i,src);
            height = max(height , 1 + depth[i]);
        }
    }
    depth[src] = height;
}
void solve(int src , int parent , int parent_ans)
{
    vector<int>prefix , suffix;
    for(auto i : adj[src])
    {
        if(i!=parent)
        {
            prefix.push_back(depth[i]);
            suffix.push_back(depth[i]);
        }
    }
    for(int i = 1 ; i< prefix.size() ; i++)
    {
        prefix[i] = max(prefix[i] , prefix[i-1]);
    }
    for(int i = suffix.size() -2 ; i>=0 ; i--)
    {
        suffix[i] = max(suffix[i] , suffix[i+1]);
    }
    int child_no = 0;
    for(auto i : adj[src])
    {
        if(i!=parent)
        {
            int op1 = (child_no==0) ? INT_MIN : prefix[child_no - 1];
            int op2 = (child_no==suffix.size()-1    ) ? INT_MIN : suffix[child_no + 1];
            int partial_ans = 1 + max(parent_ans , max(op1 ,op2));

            solve( i, src , partial_ans);
            child_no++;
        }
    }
    ans[src] = 1 + max(parent_ans , prefix.empty() ? -1 : prefix.back());
}
signed main() {
    
    int n;
    cin>>n;
    
    for(int i =0 ; i < n-1 ; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);

        // ab aap smjhiye 
    }
    eval_depth(1 , 0);
    solve(1 , 0 , -1);
    for(int i =1  ; i<=n ; i++)
    {
        cout<<ans[i] << " ";
    }
    return 0;
}