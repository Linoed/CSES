#include <bits/stdc++.h>


using namespace std;


int n, t;

int k[200010];


bool can(long long time) {
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        res += time / k[i];
        if (res >= t) return true;
    }
    return false;
}

int main(void) {

    cin >> n >> t;

    for (int i = 0; i < n; ++i) cin >> k[i];


    long long lo = 1;
    long long hi = 1e18;
    long long res = 1e18;

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