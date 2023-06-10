#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;

int tree[4 * maxn];

void update(int cl, int cr, int idx, int p, int v) {
    if (cr - cl == 1) {
        tree[idx] = v;
        return;
    }

    int mid = (cl + cr) / 2;
    if (p < mid) update(cl, mid, 2 * idx + 1, p, v);
    else update(mid, cr, 2 * idx + 2, p, v);
    tree[idx] = min(tree[2 * idx + 1], tree[2 * idx + 2]);

}

int query(int cl, int cr, int ql, int qr, int idx) {
    if (cl == ql && cr == qr) {
        return tree[idx];
    }

    int mid = (cl + cr) / 2;
    int res = 1e9;
    if (ql < mid) res = min(res, query(cl, mid, ql, min(mid, qr), 2 * idx + 1));
    if (qr > mid) res = min(res, query(mid, cr, max(mid, ql), qr, 2 * idx + 2));
    return res;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 4 * maxn; ++i) tree[i] = 1e9;
    int n, q;
    cin >> n >> q;
    int x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        update(0, n, 0, i, x);
    }

    int a, b;
    for (int i = 0; i < q; ++i) {
        cin >> a >> b;
        --a, --b;
        cout << query(0, n, a, b + 1, 0) << '\n';
    }

}