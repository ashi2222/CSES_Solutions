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
int dm(vector<vector<int>>&edges)
    {
        
        int n = edges.size() + 1 ;
        for(auto i : edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int>dep(n  , 0);
        function<void(int,int)>dfs = [&](int u , int p)
        {
            for(auto v : adj[u])
            {
                if(v!=p)
                {
                    dep[v] = dep[u] + 1;
                    dfs(v , u);
                }
            }
        };
        dfs(1, -1);
        int farthest = max_element(dep.begin() , dep.end()) - dep.begin();

        fill(dep.begin() , dep.end(), 0);
        dfs(farthest , -1);
        int finalans = *max_element(dep.begin() , dep.end());
        return finalans;
        // ab aap smjhiyega 

    }

int downpaths[200001];
int diameters[200001];
void calc_downpaths(int src , int parent )
{
    
    int bestpath = 0;
    bool leaf = 1;
    for(auto child : adj[src])
    {
        if(child != parent)
        {
            leaf = 0;
            calc_downpaths(child,src);
            bestpath = max(bestpath , downpaths[child]);
        }
    }
    if(leaf)downpaths[src] = 0;
    else downpaths[src] = 1 + bestpath;
}

void solve(int src , int parent)
{
    int ans =0 ;
    vector<int>childpaths;
    for(auto child : adj[src])
    {
        if(child != parent)
        {
            solve(child , src);
            childpaths.push_back(downpaths[child]);
            ans = max(ans , diameters[child]);
        }
    }
    int childrens = childpaths.size();
    sort(childpaths.begin() , childpaths.end());
    if(childrens == 0)diameters[src] = 0;
    else if(childrens == 1)diameters[src] = 1 + childpaths[0] ;
    else diameters[src] = 2 + childpaths[childrens - 1] + childpaths[childrens - 2];
    diameters[src] = max(diameters[src] , ans);

}
// Another Method 

signed main() {
    
    int n;
    cin>>n;
    vector<vector<int>>mat;

    for(int i =0 ; i < n-1 ;i++)
    {
        int u,v;
        cin>>u>>v;
        mat.push_back({u,v});
    }
    for(auto i : mat)
    {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
    }
    //cout<<dm(mat)<<endl;
    calc_downpaths(1 , 0 );
    solve(1 , 0);
    cout<<diameters[1]<<endl;

    return 0;
}