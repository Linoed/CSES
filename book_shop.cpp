#include <bits/stdc++.h>
 
using namespace std;
 
int price[1010];
int page[1010];
 
int dp[1010][100010] = {0};
 
int main(void) {
    int n, x;
    cin >> n >> x;
 
    for (int i = 0; i < n; ++i) cin >> price[i];
    for (int i = 0; i < n; ++i) cin >> page[i];
 
 
    int res = 0;
    for (int j = 1; j <= n; ++j) {
        for (int i = 1; i <= x; ++i) {
            dp[j][i] = max(dp[j][i - 1], dp[j - 1][i]);
            if (i - price[j - 1] >= 0) dp[j][i] = max(dp[j][i], dp[j - 1][i - price[j - 1]] + page[j - 1]);
            res = max(res, dp[j][i]);
        }
    }
 
    cout << res << '\n';
 
    // dp[j][i] maximum number of pages using up to j books and i money
    // dp[j][i] comes from dp[j][i - 1]
    // and dp[j - 1][i - price[j - 1]]
 
}