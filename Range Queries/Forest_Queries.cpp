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


class SGTree {
public: vector<int> seg;
public:
    SGTree(int n) {
        seg.resize(4 * n + 1);
    }
 
    void build(int ind, int low1  , int low2 , int high1, int high2 , vector<vector<int>>&mat) {
       if(low1  == low2 and high1 == high2)
       {
            if(mat[low1][low2] == '*')
            {
                seg[ind] = 1;
            }
            else seg[ind] = 0;
       }
        int mid1 = (low1 + high1)/2;
        int mid2 = (low2 + high2)/2;
        build(2 * ind + 1, low1 , low2 , mid1 , mid2 , mat);
        build(2 * ind + 2, mid1+1 , mid2 + 1 , high1 , high2 , mat );     
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }
 
    int query(int ind, int low1 , int low2 , int high1 , int high2 , int l1 ,int l2 , int r1 , int r2)
    {
        // no overlap
        // l r low high or low high l r
        
        
    }
    
};

signed main() {
    int n,q;
    cin>>n>>q;
    SGTree st(n);
    vector<vector<char>>mat(n , vector<int>(n));
    for(int i = 0 ;i < n ;i++)
    {
        for(int j =0 ;j < n ;j++)
        {
            cin>>mat[i][j];
        }
    }
    // ab aap dekhiye 


    return 0;
}