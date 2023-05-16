#include <bits/stdc++.h>
 
using namespace std;
 
int dp[5010][5010];
 
int main(void) {
 
    string a, b;
    cin >> a >> b;
 
    int m = a.size();
    int n = b.size();
 
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            dp[i][j] = 1e9;
        }
    }
 
    dp[0][0] = 0;
    for (int i = 1; i <= m; ++i) {
        dp[i][0] = i;
    }
    for (int j = 1; j <= n; ++j) {
        dp[0][j] = j;
    }
 
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            dp[i][j] = min({dp[i][j], dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1});
        }
    }
    cout << dp[m][n] << '\n';
}
 
// dp[i][j] min operations to transform first i chars to first j chars
// if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1]
// otherwise dp[i][j] = dp[i - 1][j], dp[i][j - 1]