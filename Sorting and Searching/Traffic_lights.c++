//Ashish Patel

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define forn(i,n) for(int i = 0; i <n;i++) 
#define invec(a,n)  vector<ll>a; for(ll i =0 ; i < n ; i++){ll x ; cin>>x; a.push_back(x);}
#define outvec(a,n) for(int i =0 ; i < n ; i++){cout<<a[i]<<" ";}cout<<endl;
#define vec(a,n) vector<int>a(n,0);
#define yes cout<<"YES"<<endl;
#define srt(a) sort(a.begin() , a.end());
#define no cout<<"NO"<<endl;

int main() {
    
    ll X,N;
    cin>>X>>N;
    vector<ll>P(N);
    for(ll i=0 ; i < N ; i++)
    {
        cin>>P[i];
    }
    set<pair<int, int> > ranges;
    ranges.insert({ 0, X });
    multiset<ll> range_lengths;
    range_lengths.insert(X);

    for (int i = 0; i < N; i++) {
        ll pos = P[i];
        
        auto it = ranges.upper_bound({ pos, 0 });
        it--;

        ll start = it->first;
        ll end = it->second;

        ranges.erase(it);
        range_lengths.erase(
            range_lengths.find(end - start));

       
        ranges.insert({ start, pos });
        ranges.insert({ pos, end });
        range_lengths.insert(pos - start);
        range_lengths.insert(end - pos);

        cout << *range_lengths.rbegin() << "\n";
    }
}