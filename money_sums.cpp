#include <bits/stdc++.h>


using namespace std;


bool dp[101][100001];
int x[101];

int main(void) {

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) cin >> x[i];

    dp[0][0] = true;
    dp[0][x[0]] = true;

    for (int i = 1; i < n; ++i) {
        dp[i][0] = true;
        int val = x[i];
        for (int j = 1; j <= 100000; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j - val >= 0 && dp[i - 1][j - val]) dp[i][j] = true;
        }
    }
    
    vector<int> res;
    for (int i = 1; i <= 100000; ++i) {
        if (dp[n - 1][i]) res.push_back(i);
    }
    cout << res.size() << '\n';
    for (auto x : res) cout << x << ' ';
    cout << '\n';

}


