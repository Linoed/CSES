#define MOD 1000000007
#include <bits/stdc++.h>
using namespace std;

long long dp[1 << 20][21];

int radj[21][21];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        radj[--b][--a]++;
    }

    dp[1][0] = 1;

    for (int i = 2; i < (1 << n); ++i) {
        if ((i & (1 << (n - 1))) && i != (1 << n) - 1) continue;
        for (int j = 0; j < n; ++j) {
            if (!(i & (1 << j))) continue;
            for (int u = 0; u < n; ++u) {
                if (!radj[j][u]) continue;
                dp[i][j] = (radj[j][u] * (dp[i][j] + dp[i ^ (1 << j)][u])) % MOD;
            }
        }
    }

    cout << dp[(1 << n) - 1][n - 1] << '\n';
}


// dp[mask][j] number of ways to visit mask ending at j
// dp[mask][j] can come from dp[mask ^ j][i] where edge i j