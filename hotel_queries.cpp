#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;

int tree[4 * maxn];
int h[maxn];

void update(int cl, int cr, int u, int i, int v) {
    if (cr - cl == 1) {
        tree[i] = v;
        return;
    }

    int mid = (cl + cr) / 2;
    if (u < mid) update(cl, mid, u, 2 * i + 1, v);
    else update(mid, cr, u, 2 * i + 2, v);
    tree[i] = max(tree[2 * i + 1], tree[2 * i + 2]);
}

int findI(int cl, int cr, int i, int v) {
    if (cr - cl == 1) return cl;

    int mid = (cl + cr) / 2;
    if (tree[2 * i + 1] >= v) return findI(cl, mid, 2 * i + 1, v);
    return findI(mid, cr, 2 * i + 2, v);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int x;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        h[i] = x;
        update(0, maxn, i, 0, x);
    }

    int r;
    for (int i = 0; i < m; ++i) {
        cin >> r;
        if (tree[0] < r) {
            cout << "0 ";
            continue;
        }
        int idx = findI(0, maxn, 0, r);
        cout << idx << ' ';
        h[idx] -= r;
        update(0, maxn, idx, 0, h[idx]);
    }
    cout << '\n';
}