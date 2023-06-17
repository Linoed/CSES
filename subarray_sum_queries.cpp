#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;

// left maximum subarray sum starting at left side of node
// right maximum subarray sum starting at right side of node
// best maximum subarray sum of the node
// sum total sum of the node

// node.best = max(leftChild.best, rightChild.best, leftChild.right + rightChild.left)
// node.left = max(leftChild.left, leftChild.sum + rightChild.left)
// node.right = max(rightChild.right, rightChild.sum + leftChild.right)
// node.sum = leftChild.sum + rightChild.sum

struct node {
    long long left = 0, right = 0, best = 0, sum = 0;

    void upd(long long a, long long b, long long c, long long d) {
        left = a, right = b, best = c, sum = d;
    }
};

node tree[4 * maxn];

void update(int cl, int cr, int u, int i, int v) {
    if (cr - cl == 1) {
        tree[i].upd(v, v, v, v);
        return;
    }

    int mid = (cl + cr) / 2;

    if (u < mid) update(cl, mid, u, 2 * i + 1, v);
    else update(mid, cr, u, 2 * i + 2, v);

    tree[i].sum = tree[2 * i + 1].sum + tree[2 * i + 2].sum;
    tree[i].best = max({tree[2 * i + 1].best, tree[2 * i + 2].best, tree[2 * i + 1].right + tree[2 * i + 2].left});
    tree[i].left = max(tree[2 * i + 1].left, tree[2 * i + 1].sum + tree[2 * i + 2].left);
    tree[i].right = max(tree[2 * i + 2].right, tree[2 * i + 2].sum + tree[2 * i + 1].right);
}

// query the max subarray sum in a range, not needed for this question
node query(int cl, int cr, int ql, int qr, int i) {
    if (cl == ql && cr == qr) {
        return tree[i];
    }

    int mid = (cl + cr) / 2;
    node l, r;

    if (ql < mid) l = query(cl, mid, ql, min(qr, mid), 2 * i + 1);
    if (qr > mid) r = query(mid, cr, max(ql, mid), qr, 2 * i + 2);

    node res;
    res.sum = l.sum + r.sum;
    res.best = max({l.best, r.best, l.right + r.left});
    res.right = max(r.right, r.sum + l.right);
    res.left = max(l.left, l.sum + r.left);
    return res;
}



int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int x;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        update(0, maxn, i, 0, x);
    }

    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        update(0, maxn, a, 0, b);
        cout << tree[0].best << '\n';
    }
}










