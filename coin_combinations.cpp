#define MOD 1000000007
#include <bits/stdc++.h>

using namespace std;

int dp[1000010];
int c[1000010];

// online judge is incredibly tight on this one
int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    dp[0] = 1;

    int n, x;
    cin >> n >> x;

    for (int i = 0; i < n; ++i) cin >> c[i];

    // attempt to pass tight online judge, not necessary at all
    sort(c, c + n);

    for (int i = 1; i <= x; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i - c[j] < 0) break;
            dp[i] = (dp[i] + dp[i - c[j]]) % MOD;
        }
    }

    cout << (dp[x] % MOD + MOD) % MOD << '\n';
}