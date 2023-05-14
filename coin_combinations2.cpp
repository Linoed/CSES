#define MOD 1000000007
#include <bits/stdc++.h>

using namespace std;


int dp[1000010];
int c[1000010];

int main(void) {

    int n, x;
    cin >> n >> x;

    dp[0] = 1;

    for (int i = 0; i < n; ++i) cin >> c[i];

    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= x; ++j) {
            if (j - c[i] >= 0) dp[j] = (dp[j] + dp[j - c[i]]) % MOD;
        }
    }

    cout << (dp[x] % MOD + MOD) % MOD << '\n';
}