#include <bits/stdc++.h>
using namespace std;

int dp[32][200010];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;

    int t;
    for (int i = 1; i <= n; ++i) {
        cin >> t;
        dp[0][i] = t;
    }

    for (int j = 1; j < 32; ++j) {
        for (int i = 1; i <= n; ++i) {
            dp[j][i] = dp[j - 1][dp[j - 1][i]];
        }
    }

    int x, k;
    for (int i = 0; i < q; ++i) {
        cin >> x >> k;
        for (int j = 0; j < 32; ++j) {
            if (k & 1) {
                x = dp[j][x];
            }
            k >>= 1;
        }
        cout << x << '\n';
    }
}


// dp[j][i] node that is 2^j edges away from i
// dp[0][i] = tele[i]
// dp[1][i] = dp[0][x] where x is dp[0][i]
// dp[j][i] = dp[j - 1][dp[j - 1][i]]