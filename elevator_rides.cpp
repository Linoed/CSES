#include <bits/stdc++.h>


using namespace std;


pair<int, int> dp[1 << 20];
int w[21];


int main(void) {

    int n, x;
    cin >> n >> x;

    for (int i = 0; i < n; ++i) cin >> w[i];

    dp[0] = {1, 0};
    for (int i = 1; i < (1 << n); ++i) {
        pair<int, int> best = {n, 0};
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                auto choice = dp[i ^ (1 << j)];
                if (choice.second + w[j] <= x) {
                    best = min(best, {choice.first, choice.second + w[j]});
                }
                else {
                    best = min(best, {choice.first + 1, w[j]});
                }
            }
        }
        dp[i] = best;
    }
    cout << dp[(1 << n) - 1].first << '\n';
}

