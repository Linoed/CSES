#include <bits/stdc++.h>
using namespace std;

long long x[200010];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    int v;
    for (int i = 1; i <= n; ++i) {
        cin >> v;
        x[i] = v + x[i - 1];
    }

    int a, b;
    for (int i = 0; i < q; ++i) {
        cin >> a >> b;
        cout << x[b] - x[a - 1] << '\n';
    }

}