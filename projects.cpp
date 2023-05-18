#include <bits/stdc++.h>

using namespace std;

struct data {
    int s, e, p;
};

long long dp[200010];

int main(void) {
    int n;
    cin >> n;

    vector<data> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].s >> v[i].e >> v[i].p;
    }

    sort(v.begin(), v.end(), [](const data& a, const data& b) {
        if (a.e != b.e) return a.e < b.e;
        return a.s < b.s;
    });

    dp[0] = v[0].p;

    for (int i = 1; i < n; ++i) {
        dp[i] = dp[i - 1];
        // last element that has x.e < v[i].s
        int lo = 0;
        int hi = i - 1;
        int res = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (v[mid].e < v[i].s) {
                res = mid;
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        if (res == -1) {
            dp[i] = max(dp[i], (long long)v[i].p);
        }
        else {
            dp[i] = max(dp[i], v[i].p + dp[res]);
        }
    }

    cout << dp[n - 1] << '\n';

}