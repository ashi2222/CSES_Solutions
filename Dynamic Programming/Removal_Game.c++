#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define forn(i, n) for(int i = 0; i < n; i++) 
#define invec(a, n) vector<ll> a(n); for(int i = 0; i < n; i++) { cin >> a[i]; }

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    vector<vector<ll>> dp(n, vector<ll>(n));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            if (i == j) {
                dp[i][j] = a[i];
            } else {
                dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);
            }
        }
    }
    ll sum = accumulate(a.begin() ,a.end(), 0ll);
    cout << (sum + dp[0][n - 1]) / 2 << "\n";
}

int main() {
    solve();
    // ll n;
    // cin >> n;
    //solve(a, n);
    //cout << solve(a, n) << endl;
    return 0;
}
