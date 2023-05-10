#include <bits/stdc++.h>


using namespace std;

char board[8][8];

dp[8][260] = {0};



int main(void) {

    for (int j = 0; j < 8; ++j) {
        for (int i = 0; i < 8; ++i) {
            cin >> board[j][i];
        }
    }

    for (int i = 0; i < 8; ++i) {
        if (board[0][i] == '.') dp[0][1 << i] = 1;
    }

    for (int j = 1; j < 8; ++j) {

    }

    cout << dp[7][(1 << 8) - 1] << "\n";
}


// dp[j][mask]

// number of ways to place queens up to j using mask columns

// when placing a queen
// dp

// store the diags and antidiags?


