#include <bits/stdc++.h>
 
using namespace std;
 
int dp[510][510] = {0};
 
int solve(int a, int b) {
    if (a == b) return 0;
    if (dp[a][b] != 0) return dp[a][b];
 
    int res = 1e9;
    // check the cols
    if (a != 1) {
        for (int i = 1; i < a; ++i) {
            res = min(res, solve(i, b) + solve(a - i, b));
        }
    }
 
    // check the rows
    if (b != 1) {
        for (int i = 1; i < b; ++i) {
            res = min(res, solve(a, i) + solve(a, b - i));
        }
    }
 
    dp[a][b] = res + 1;
    return res + 1;
}
 
 
int main(void) {
    int a, b;
    cin >> a >> b;
 
    cout << solve(a, b) << '\n';
 
}
 
 
// dp(i, j) min number of moves to turn i x j rectangle into square
// if i == j dp(i, j) = 0
// at dp(i, j), you can cut across the rows or the columns