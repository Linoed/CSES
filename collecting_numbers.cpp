#include <bits/stdc++.h>


using namespace std;

int idx[200010];
int x[200010];


int main(void) {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) cin >> x[i];

    iota(idx, idx + n, 0);
    sort(idx, idx + n, [&](const int a, const int b) {
        return x[a] < x[b];
    });

    int res = 1;
    for (int i = 1; i < n; ++i) {
        if (idx[i] < idx[i - 1]) ++res;
    }

    cout << res << "\n";


}