#include <bits/stdc++.h>
using namespace std;

long long bit[200010];

long long prefix(int x) {
    long long res = 0;
    for (int i = x; i > 0; i -= (i & -i)) res += bit[i];
    return res;
}

long long query(int l, int r) {
    return prefix(r) - prefix(l - 1);
}

void add(int x, int val) {
    for (int i = x; i < 200010; i += (i & -i)) bit[i] += val;
}

void update(int x, int val) {
    int curr = query(x, x);
    add(x, val - curr);
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

    int a, b, c;
    for (int i = 0; i < q; ++i) {
        cin >> a >> b >> c;
        if (a == 1) {
            update(b, c);
        }
        else {
            cout << query(b, c) << '\n';
        }
    }


}