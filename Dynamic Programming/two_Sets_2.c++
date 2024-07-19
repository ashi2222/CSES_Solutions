#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const int mod = 1e9 + 7;

// Function to compute the number of ways to partition the set
ll solve(ll n) {
    ll sum = (n * (n + 1)) / 2;
    
    // If the sum is odd, it's not possible to partition into two equal subsets
    if (sum % 2 != 0) {
        return 0;
    }
    
    ll target = sum / 2;
    vector<ll> dp(target + 1, 0);
    dp[0] = 1;

    // Dynamic programming approach to count subsets with given sum
    for (ll i = 1; i <= n; ++i) {
        for (ll j = target; j >= i; --j) {
            dp[j] = (dp[j] + dp[j - i]) % mod;
        }
    }

    // The answer is the number of ways to make 'target' divided by 2
    return dp[target] * ((mod + 1) / 2) % mod; // Mod inverse of 2 under mod
}

int main() {
   {
        ll n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}
