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
    ll n,k;
    cin>>n>>k;
    invec(a,n)
    int j=0;
    multiset<ll>st1 , st2;
    ll sum1 =0 , sum2 =0 ;
    for(int i =0 ; i < n ;i++)
    {
        if(i>=k)
        {
            if(st1.find(a[i-k])!=st1.end())
            {
                st1.erase(st1.find(a[i-k]));
                sum1 -= a[i-k];
            }
            else{
                st2.erase(st2.find(a[i-k]));
                sum2 -= a[i-k];
            }
        }
        ll size1 = st1.size();
        ll size2 = st2.size();
        if(size1 <= size2)
        {
            st1.insert(a[i]);
            sum1 += a[i];
        }
        else{
            st2.insert(a[i]);
            sum2 += a[i];
        }
        size1 = st1.size();
        size2 = st2.size();
        if(size1 > 0 and size2 > 0)
        {
            auto max_st1 = st1.rbegin();
            auto min_st2 = st2.begin();
            if(*max_st1 > *min_st2)
            {
                sum1 = sum1 - *max_st1 + *min_st2;
                sum2 = sum2 - *min_st2 + *max_st1;
                st1.insert(*min_st2);
                st2.insert(*max_st1);
                st1.erase(st1.find(*max_st1));
                st2.erase(st2.find(*min_st2));
            }
        }
        if(i>=k-1)
        {
            ll median = *st1.rbegin();
            ll ans =( st1.size()*median - sum1 )+ (sum2 - st2.size()*median);
            cout<<ans<<" ";
        }
    }
    cout<<endl;
    return 0;
}