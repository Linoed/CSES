#include <bits/stdc++.h>


using namespace std;

int x[5010];

bool cache[5010][5010];
pair<long long, long long> dp[5010][5010];

// first, second scores
pair<long long, long long> solve(int l, int r, bool first) {
    if (l == r) return {x[l] * first, x[l] * (!first)};
    if (cache[l][r]) return dp[l][r];

    auto left = solve(l + 1, r, !first);
    auto right = solve(l, r - 1, !first);
    cache[l][r] = true;
    if (first) {
        // choose between
        // left.first + x[l]
        // right.first + x[r]
        if (left.first + x[l] > right.first + x[r]) {
            dp[l][r] = {left.first + x[l], left.second};
            return {left.first + x[l], left.second};
        }
        dp[l][r] = {right.first + x[r], right.second};
        return {right.first + x[r], right.second};
    }
    else {
        if (left.second + x[l] > right.second + x[r]) {
            dp[l][r] = {left.first, left.second + x[l]};
            return {left.first, left.second + x[l]};
        }
        dp[l][r] = {right.first, right.second + x[r]};
        return {right.first, right.second + x[r]};
    }
}

int main(void) {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) cin >> x[i];

    cout << solve(0, n - 1, true).first << '\n';
}


// each player will choose the number that gives them the highest score