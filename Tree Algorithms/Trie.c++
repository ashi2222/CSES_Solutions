#define ll long long
class Solution {
public:
    
     long long countSubarrays(vector<int>& a, int k) {
        int n = a.size();
        ll ans = 0;
        unordered_map<ll, ll> finalmp;
        

        for (int i = 0; i < n; ++i) {
            unordered_map<ll, ll> dummy; 

            if (a[i] == k) {
                ++ans;
            }
            dummy[a[i]] = 1;

            for (auto v : finalmp) {
                ll val = v.first;
                ll freq = v.second;
                ll ashu = val & a[i];
                if (ashu == k) {
                    ans += freq;
                }
                dummy[newAndResult] += freq;
            }
            
            finalmp = dummy;
        }
        
        return ans;
    }
};

D