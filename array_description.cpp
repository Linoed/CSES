#define MOD 1000000007
#include <bits/stdc++.h>
 
using namespace std;
 
int x[100010];
 
int dp[100010][101] = {0};
 
int main(void) {
 
    int n, m;
    cin >> n >> m;
 
    for (int i = 0; i < n; ++i) cin >> x[i];
 
    // dp[i][j] number of arrays up to i ending with element j
 
    if (x[0] == 0) {
        for (int i = 1; i <= m; ++i) dp[0][i] = 1;
    }
    else {
        dp[0][x[0]] = 1;
    }
 
    for (int i = 1; i < n; ++i) {
        if (x[i] == 0) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
                dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
 
            }
        }
        else {
            dp[i][x[i]] = (dp[i][x[i]] + dp[i - 1][x[i] - 1]) % MOD;
            dp[i][x[i]] = (dp[i][x[i]] + dp[i - 1][x[i]]) % MOD;
            dp[i][x[i]] = (dp[i][x[i]] + dp[i - 1][x[i] + 1]) % MOD;
        }
    }
 
    int res = 0;
    for (int i = 1; i <= m; ++i) res = (res + dp[n - 1][i]) % MOD;
    cout << (res % MOD + MOD) % MOD << '\n';
}
 
// dp[i][j] can come from dp[i - 1][j - 1], dp[i - 1][j], dp[i - 1][j + 1]