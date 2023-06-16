#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;

int x[maxn];

long long tree[4 * maxn];
long long lazy[4 * maxn];

// tree[i] data of the node
// lazy[i] data yet to be pushed to the children of the node

// if we've reached tree[i], tree[i] is always correct

// when at tree[i], need to push lazy[i] to lazy[left], tree[left] and lazy[right], tree[right]

void push(int i) {
    tree[2 * i + 1] += lazy[i];
    tree[2 * i + 2] += lazy[i];
    lazy[2 * i + 1] += lazy[i];
    lazy[2 * i + 2] += lazy[i];
    lazy[i] = 0;
}

void update(int cl, int cr, int ul, int ur, int i, int add) {

    if (cl == ul && cr == ur) {
        tree[i] += add;
        lazy[i] += add;
        return;
    }

    push(i);
    int mid = (cl + cr) / 2;

    if (ul < mid) update(cl, mid, ul, min(mid, ur), 2 * i + 1, add);
    if (ur > mid) update(mid, cr, max(mid, ul), ur, 2 * i + 2, add);
    tree[i] = max(tree[2 * i + 1], tree[2 * i + 2]);
}

long long query(int cl, int cr, int ql, int qr, int i) {

    if (cl == ql && cr == qr) {
        return tree[i];
    }

    push(i);
    int mid = (cl + cr) / 2;
    long long res = -1e15;
    if (ql < mid) res = max(res, query(cl, mid, ql, min(qr, mid), 2 * i + 1));
    if (qr > mid) res = max(res, query(mid, cr, max(mid, ql), qr, 2 * i + 2));
    return res;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
        // increase [i..n] by x[i]
        update(0, maxn, i, n + 1, 0, x[i]);
    }

    // for each query, query the maximum prefix sum in the range [a..b]
    // then reduce this by the prefix sum of [0..a-1]

    int qt, a, b;
    for (int i = 0; i < q; ++i) {
        cin >> qt >> a >> b;
        if (qt == 1) {
            int addend = b - x[a];
            update(0, maxn, a, n + 1, 0, addend);
            x[a] = b;
        }
        else {
            cout << max(query(0, maxn, a, b + 1, 0) - query(0, maxn, a - 1, a, 0), 0LL) << '\n';
        }
    }
}