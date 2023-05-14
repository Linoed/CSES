#define MOD 1000000007
#include <bits/stdc++.h>

using namespace std;


int dp[1010][1010];
char grid[1010][1010];

int main(void) {

    int n;
    cin >> n;

    

    dp[0][0] = 1;

    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < n; ++i) {
            cin >> grid[j][i];
        }
    }

    if (grid[0][0] == '*') {
        cout << "0\n";
        return 0;
    }

    for (int i = 1; i < n; ++i) {
        if (grid[0][i] == '.') dp[0][i] = dp[0][i - 1];
        if (grid[i][0] == '.') dp[i][0] = dp[i - 1][0];
    }

    for (int j = 1; j < n; ++j) {
        for (int i = 1; i < n; ++i) {
            if (grid[j][i] == '.') dp[j][i] = (dp[j - 1][i] + dp[j][i - 1]) % MOD;
        }
    }
    cout << (dp[n - 1][n - 1] % MOD + MOD) % MOD << '\n';
}
