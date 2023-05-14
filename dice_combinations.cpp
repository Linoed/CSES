#define MOD 1000000007
#include <bits/stdc++.h>

using namespace std;

int dp[1000010];

int modadd(int a, int b) {
    return ((a + b) % MOD + MOD) % MOD;
}

int main(void) {

    int n;
    cin >> n;

    dp[0] = 1;

    // can use matrix exponentiation
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 6; ++j) {
            if (i - j >= 0) dp[i] = modadd(dp[i], dp[i - j]);
        }
    }

    cout << dp[n] << '\n';

}