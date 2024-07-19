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
 
    void build(int ind, int low, int high, int arr[]) {
        if (low == high) {
            seg[ind] = arr[low];
            return;
        }
 
        int mid = (low + high) / 2;
        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);
        seg[ind] = min(seg[2 * ind + 1] , seg[2 * ind + 2]);
    }
 
    int query(int ind, int low, int high, int l, int r) {
        // no overlap
        // l r low high or low high l r
        if (r < low || high < l) return INT_MAX;
 
        // complete overlap
        // [l low high r]
        if (low >= l && high <= r) return seg[ind];
 
        int mid = (low + high) >> 1;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return min(left , right);
    }
    void update(int ind, int low, int high, int i, int val) {
        if (low == high) {
            seg[ind] = val;
            return;
        }
 
        int mid = (low + high) >> 1;
        if (i <= mid) update(2 * ind + 1, low, mid, i, val);
        else update(2 * ind + 2, mid + 1, high, i, val);
        seg[ind] = min(seg[2 * ind + 1] , seg[2 * ind + 2]);
    }
};

signed main() {
    int n,q;
    cin>>n>>q;
    SGTree st(n);
    int a[n];
    for(int i = 0;i < n ;i++)
    {
        cin>>a[i];
    }
    st.build(0,0,n-1 , a);
    while(q--)
    {
        int type,l,r;
        cin>>type>>l>>r;
        l--;
        if(type == 1)
        {
            st.update(0,0,n-1 , l , r);
        }
        else{
            r--;
            cout<<st.query(0,0,n-1 , l,r)<<endl;
        }
    }

    return 0;
}