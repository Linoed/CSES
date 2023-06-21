#include <bits/stdc++.h>
using namespace std;

// mo's algorithm with coordinate compression

// const int maxn = 200010;
// const int block_size = 450;

// struct query {
//     int a, b, block, idx;

//     query(void) {

//     }

//     query(int _a, int _b, int _block, int _idx) {
//         a = _a;
//         b = _b;
//         block = _block;
//         idx = _idx;
//     }
// };

// int x[maxn];
// int cnt[maxn];
// int ans[maxn];
// query queries[maxn];

// map<int, int> mp;

// int main(void) {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int n, q;
//     cin >> n >> q;

//     // coordinate compression
//     int order = 0;
//     for (int i = 1; i <= n; ++i) {
//         cin >> x[i];
//         if (mp.count(x[i])) x[i] = mp[x[i]];
//         else {
//             mp[x[i]] = order;
//             x[i] = order++;
//         }
//     }

//     int a, b;
//     for (int i = 0; i < q; ++i) {
//         cin >> a >> b;
//         queries[i] = query(a, b, a / block_size, i);
//     }

//     sort(queries, queries + q, [](const query& a, const query& b) {
//         if (a.block != b.block) return a.block < b.block;
//         return a.b < b.b;
//     });

//     int res = 1;
//     int l = queries[0].a, r = queries[0].a;
//     cnt[x[l]]++;

//     // mo's algorithm
//     for (int i = 0; i < q; ++i) {
//         auto& qry = queries[i];

//         while (l != qry.a || r != qry.b) {
//             if (r > qry.b) {
//                 if (cnt[x[r]] == 1) --res;
//                 cnt[x[r--]]--;
//             }
//             if (r < qry.b) {
//                 if (!cnt[x[++r]]) ++res;
//                 cnt[x[r]]++;
//             }
//             if (l > qry.a) {
//                 if (!cnt[x[--l]]) ++res;
//                 cnt[x[l]]++;
//             }
//             if (l < qry.a) {
//                 if (cnt[x[l]] == 1) --res;
//                 cnt[x[l++]]--;
//             }
//         }

//         ans[qry.idx] = res;
//     }

//     for (int i = 0; i < q; ++i) cout << ans[i] << '\n';
// }

// second solution
struct query {
    int b, i;

    query(void) {}
    query(int _b, int _i) {
        b = _b, i = _i;
    }
};

const int maxn = 200010;
int bit[maxn];
int x[maxn];
int ans[maxn];
vector<query> queries[maxn];

void add(int x, int v) {
    for (int i = x; i < maxn; i += (i & -i)) bit[i] += v;
}

int prefix(int x) {
    int res = 0;
    for (int i = x; i; i -= (i & -i)) res += bit[i];
    return res;
}

int queryTree(int l, int r) {
    return prefix(r) - prefix(l - 1);
}

void update(int x, int v) {
    int curr = queryTree(x, x);
    int addend = v - curr;
    add(x, addend);
}



// index of first occurrence of a value is set to 1
// subsequent duplicates are set to 0
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }

    int a, b;
    for (int i = 0; i < q; ++i) {
        cin >> a >> b;
        queries[a].push_back(query(b, i));
    }

    // first (leftmost) occurrence of a value
    map<int, int> mp;

    for (int i = n; i; --i) {
        if (mp.count(x[i])) {
            update(mp[x[i]], 0);
        }
        mp[x[i]] = i;
        update(i, 1);
        for (auto& q : queries[i]) {
            ans[q.i] = queryTree(i, q.b);
        }
    }

    for (int i = 0; i < q; ++i) cout << ans[i] << '\n';
}