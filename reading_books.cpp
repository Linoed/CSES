#include <bits/stdc++.h>

using namespace std;

int t[200010];

int main(void) {

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) cin >> t[i];

    long long sum = 0;
    int mxm = 0;
    for (int i = 0; i < n; ++i) {
        sum += t[i];
        mxm = max(mxm, t[i]);
    }

    if (sum <= 2 * mxm) {
        cout << 2 * mxm << '\n';
        return 0;
    }
    cout << sum << '\n';

    // if sum <= largest
    // then bottlenecked by largest, return 2 * largest

    // if sum > largest
    // then not bottlenecked, return sum


}