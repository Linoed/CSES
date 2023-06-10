#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;

int tree[4 * maxn];

void update(int cl, int cr, int i, int p, int val) {
    if (cr - cl == 1) {
        tree[i] = val;
        return;
    }
    
    int mid = (cl + cr) / 2;
    if (p < mid) update(cl, mid, 2 * i + 1, p, val);
    else update(mid, cr, 2 * i + 2, p, val);
    tree[i] = min(tree[2 * i + 1], tree[2 * i + 2]);
}

int query(int cl, int cr, int ql, int qr, int i) {
    if (cl == ql && cr == qr) {
        return tree[i];
    }

    int mid = (cl + cr) / 2;
    int res = 1e9;
    if (ql < mid) res = min(res, query(cl, mid, ql, min(qr, mid), 2 * i + 1));
    if (qr > mid) res = min(res, query(mid, cr, max(ql, mid), qr, 2 * i + 2));
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

    int a, b, c;
    for (int i = 0; i < q; ++i) {
        cin >> a >> b >> c;
        if (a == 1) {
            update(0, n, 0, b - 1, c);
        }
        else {
            cout << query(0, n, b - 1, c, 0) << '\n';
        }
    }
}