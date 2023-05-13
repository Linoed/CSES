#include <bits/stdc++.h>


using namespace std;


int n, k;


int x[200010];



bool can(long long val) {
    int res = 1;
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        if (x[i] > val) return false;
        sum += x[i];
        if (sum > val) {
            sum = x[i];
            ++res;
        }
    }
    return res <= k;
}


int main(void) {

    cin >> n >> k;

    for (int i = 0; i < n; ++i) cin >> x[i];

    long long lo = 1;
    long long hi = 1e15;
    long long res = 1;

    // lf lowest sum
    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;
        if (can(mid)) {
            res = mid;
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }

    cout << res << '\n';
}