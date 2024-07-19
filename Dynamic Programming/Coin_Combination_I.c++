#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
 
const ll MOD = 1e9 + 7;
 
// dp[i] = sum of { dp[i - x] }, where i >= x
 
void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    vector<int> dp(m + 1);
    dp[0] = 1;
    for (int i = 1; i <= m; i++) {
        for (int x : a) {
            if (i >= x) {
                dp[i] = (dp[i] + dp[i - x]) % MOD;
            }
        }
    }
    cout << dp[m] << "\n";
}
 
int main(){
    solve();
    return 0;
}