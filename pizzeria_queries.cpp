#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;

// if shop is to the left, total price = price + (home - shop), so store price - shop
// if shop is to the right, total price = price + (shop - home), so store price + shop

// price + index, price - index
int to[4 * maxn], from[4 * maxn];

void update(int* tree, int cl, int cr, int u, int i, int v) {
    if (cr - cl == 1) {
        tree[i] = v;
        return;
    }

    int mid = (cl + cr) / 2;
    if (u < mid) update(tree, cl, mid, u, 2 * i + 1, v);
    else update(tree, mid, cr, u, 2 * i + 2, v);
    tree[i] = min(tree[2 * i + 1], tree[2 * i + 2]);
}

int query(int* tree, int cl, int cr, int ql, int qr, int i) {
    if (cl == ql && cr == qr) return tree[i];

    int mid = (cl + cr) / 2;
    int res = 2e9;
    if (ql < mid) res = query(tree, cl, mid, ql, min(qr, mid), 2 * i + 1);
    if (qr > mid) res = min(res, query(tree, mid, cr, max(ql, mid), qr, 2 * i + 2));
    return res;
}



int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    int x;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        update(to, 0, maxn, i, 0, x + i);
        update(from, 0, maxn, i, 0, x - i);
    }

    int qt, a, b;
    for (int i = 0; i < q; ++i) {
        cin >> qt;
        if (qt == 1) {
            cin >> a >> b;
            update(to, 0, maxn, a, 0, b + a);
            update(from, 0, maxn, a, 0, b - a);
        }
        else {
            cin >> a;
            cout << min(query(to, 0, maxn, a, n + 1, 0) - a, query(from, 0, maxn, 1, a + 1, 0) + a) << '\n';
        }
    }

}