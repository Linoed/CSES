#include <bits/stdc++.h>

using namespace std;

int p[200010];
long long pref[200010];
long long suff[200010];


int main(void) {
    int n;
    cin >> n;


    for (int i = 0; i < n; ++i) cin >> p[i];

    sort(p, p + n);

    pref[0] = p[0];
    suff[n - 1] = p[n - 1];
    for (int i = 1; i < n; ++i) {
        pref[i] = pref[i - 1] + p[i];
    }
    for (int i = n - 2; i >= 0; --i) {
        suff[i] = suff[i + 1] + p[i];
    }
    long long res = 1LL << 62;
    for (int i = 0; i < n; ++i) {
        long long leftCost = (i + 1) * (long long) p[i];
        long long rightCost = (n - 1 - i) * (long long) p[i];
        res = min(res, leftCost - pref[i] + suff[i + 1] - rightCost);
    }

    // we want to move everything to p[i]
    // cost on left is (i + 1) * p[i]
    // cost on right is (n - 1 - i) * p[i]

    // curr sum on left is pref[i]
    // curr sum on right is suff[i + 1]

    // return leftCost - pref[i] + suff[i + 1] - rightCost

    cout << res << "\n";
}