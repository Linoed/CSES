// USING FENWICK TREE

// #include <bits/stdc++.h>
// using namespace std;

// long long bit[200010];

// long long query(int x) {
//     long long res = 0;
//     for (int i = x; i; i -= (i & -i)) res += bit[i];
//     return res;
// }

// void add(int x, int v) {
//     for (int i = x; i < 200010; i += (i & -i)) bit[i] += v;
// }

// void add(int a, int b, int v) {
//     add(a, v);
//     add(b + 1, -v);
// }



// int main(void) {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int n, q;
//     cin >> n >> q;

//     int x;
//     for (int i = 1; i <= n; ++i) {
//         cin >> x;
//         add(i, i, x);
//     }



//     int a, b, c, d;
//     for (int i = 0; i < q; ++i) {
//         cin >> a >> b;
//         if (a == 1) {
//             cin >> c >> d;
//             add(b, c, d);
//         }
//         else {
//             cout << query(b) << '\n';
//         }
//     }

// }

// USING SEGMENT TREE

#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;

long long tree[4 * maxn];

void update(int cl, int cr, int ul, int ur, int i, int v) {
    if (cl == ul && cr == ur) {
        tree[i] += v;
        return;
    }

    int mid = (cl + cr) / 2;
    if (ul < mid) update(cl, mid, ul, min(mid, ur), 2 * i + 1, v);
    if (ur > mid) update(mid, cr, max(mid, ul), ur, 2 * i + 2, v);
}

long long query(int cl, int cr, int i, int p) {
    if (cr - cl == 1) return tree[i];

    int mid = (cl + cr) / 2;
    if (p < mid) return tree[i] + query(cl, mid, 2 * i + 1, p);
    else return tree[i] + query(mid, cr, 2 * i + 2, p);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    int x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        update(0, n, i, i + 1, 0, x);
    }

    int a, b, c, d;
    for (int i = 0; i < q; ++i) {
        cin >> a >> b;
        if (a == 1) {
            cin >> c >> d;
            update(0, n, b - 1, c, 0, d);
        }
        else {
            cout << query(0, n, 0, b - 1) << '\n';
        }
    }

}
