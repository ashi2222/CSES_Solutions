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


class LazySGTree {
    public : 
    vector<int>seg,lazy; 
    LazySGTree(int n)
    {
        seg.resize(4*n + 1);
        lazy.resize(4*n + 1);
    }

    // ab aap smjhiye 

    void build(int index , int low , int high , vector<int>&arr)
    {
        if(low == high)
        {
            seg[index] = arr[low];
            return;
        }
        int mid = (low + (high - low)/2);
        build(2*index + 1 , low , mid , arr);
        build(2*index+2 , mid + 1 ,high , arr);
        seg[index]=  seg[2*index+1] + seg[2*index+2];
    }

    // important function 

    void update(int index , int low ,  int high , int l , int r ,  int val )
    {
        // out of bound 
        if(lazy[index]!=0)
        {
            seg[index] += (high - low + 1)*lazy[index];
            if(low != high)
            {
                // propagating downwards 
                lazy[2*index+1] += lazy[index];
                lazy[2*index+2] += lazy[index];
            }
            lazy[index] = 0;
        }
        if(low > r or high < l)return;
        if(l<=low and r>=high)
        {
            // fully reunited 
            // we have update the current value 
            seg[index] += (high - low + 1) * val;
            // now propagate towards down side 
            if(high != low)
            {
                lazy[2*index+1] += val;
                lazy[2*index+2] += val;
            }
            return;
        }
        int mid = low + (high - low) / 2 ;
        update(2*index + 1 , low , mid , l , r , val);
        update(2*index  +2 ,  mid + 1,  high , l , r , val);
        seg[index] = seg[2*index +1] + seg[2*index +2] ;
    }

    int query(int index , int low , int high  , int l , int r)
    {
        if(lazy[index]!=0)
        {
            seg[index] += (high - low + 1)*lazy[index];
            if(low != high)
            {
                // propagating downwards 
                lazy[2*index+1] += lazy[index];
                lazy[2*index+2] += lazy[index];
            }
            lazy[index] = 0;
        }
        if(low > r or high < l)return 0;
        if(low >= l and high <= r)
        {
            return seg[index];
        }
        int mid = low + (high - low)/2;
        int leftans = query(2*index + 1 , low , mid , l , r);
        int rightans = query(2*index + 2 , mid+1 , high , l, r);
        return leftans + rightans;
    }
};


signed main() {
    int n,q;
    cin>>n>>q;
    LazySGTree st(n);
    vector<int>a(n);
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    st.build(0,0,n-1 , a);
    while(q--)
    {
        int type;
        cin>>type;
        if(type == 1)
        {
            int a,b,u;
            cin>>a>>b>>u;
            a--;
            b--;
            st.update(0,0,n-1 , a, b ,u );
        }
        else{
            int k;
            cin>>k;
            cout<<st.query(0,0,n-1 , k-1 , k-1)<<endl;
        }
    }

    return 0;
}