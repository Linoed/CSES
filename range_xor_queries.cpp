#include <bits/stdc++.h>
using namespace std;

int bit[200010];

int prefix(int x) {
    int res = 0;
    for (int i = x; i > 0; i -= (i & -i)) res ^= bit[i];
    return res;
}

int query(int l, int r) {
    return prefix(r) ^ prefix(l - 1);
}

void add(int x, int v) {
    for (int i = x; i < 200010; i += (i & -i)) bit[i] ^= v;
}

void update(int x, int v) {
    int c = query(x, x);
    add(x, v ^ c);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    int x;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        update(i, x);
    }

    int a, b;
    for (int i = 0; i < q; ++i) {
        cin >> a >> b;
        cout << query(a, b) << '\n';
    }

}