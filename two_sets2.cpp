#define MOD 1000000007
#include <bits/stdc++.h>

using namespace std;

int dp[501][126000];

int modadd(int a, int b) {
    return ((a + b) % MOD + MOD) % MOD;
}

long long modpow(int n) {
    if (n == 0) return 1;
    if (n == 1) return 2;
    long long halfPow = modpow(n / 2);
    if (n & 1) return (halfPow * halfPow * 2 % MOD + MOD) % MOD;
    return (halfPow * halfPow % MOD + MOD) % MOD;
}

int main(void) {
    int n;
    cin >> n;

    if ((n * (n + 1) / 2) & 1) {
        cout << "0\n";
        return 0;
    }

    dp[0][0] = 1;

    for (int i = 1; i <= n; ++i) {
        dp[i][0] = 1;
        for (int j = 1; j <= 125250; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j - i >= 0) dp[i][j] = modadd(dp[i][j], dp[i - 1][j - i]);
        }
    }

    int target = n * (n + 1) / 4;

    // cant divide by two, need to multiply by modular inverse of 2
    cout << (dp[n][target] * modpow(MOD - 2) % MOD + MOD) % MOD << '\n';
}
