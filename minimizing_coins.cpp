#include <bits/stdc++.h>

using namespace std;


int dp[1000010];
int c[1000010];


int main(void) {

    int n, x;
    cin >> n >> x;

    for (int i = 1; i <= x; ++i) dp[i] = 1e9;

    for (int i = 0; i < n; ++i) cin >> c[i];

    for (int i = 1; i <= x; ++i) {
        for (int j = 0; j < n; ++j) {
            int val = c[j];
            if (i - val >= 0) {
                dp[i] = min(dp[i], dp[i - val] + 1);
            }
        }
    }

    cout << (dp[x] == 1e9 ? -1 : dp[x]) << '\n';
}