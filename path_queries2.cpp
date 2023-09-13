#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;

// segment tree

int tree[4 * maxn];

void update(int cl, int cr, int u, int i, int val) {
    if (cr - cl == 1) {
        tree[i] = val;
        return;
    }

    int mid = (cl + cr) / 2;
    if (u < mid) update(cl, mid, u, 2 * i + 1, val);
    else update(mid, cr, u, 2 * i + 2, val);
    tree[i] = max(tree[2 * i + 1], tree[2 * i + 2]);
}

int query(int cl, int cr, int ql, int qr, int i) {
    if (cl == ql && cr == qr) {
        return tree[i];
    }

    int mid = (cl + cr) / 2;
    int res = 0;
    if (ql < mid) res = query(cl, mid, ql, min(qr, mid), 2 * i + 1);
    if (qr > mid) res = max(res, query(mid, cr, max(mid, ql), qr, 2 * i + 2));
    return res; 
}

// segment tree


int v[maxn];
vector<int> adj[maxn];

int subtree_size[maxn];
int heavyChild[maxn];
// used for the segtree
int label[maxn];
int T = 1;

// stores the top of the chain that the node is a part of, top[u] == u if light node
int top[maxn];
int parent[19][maxn];
int depth[maxn];

void dfs_size(int u, int par, int d) {
    subtree_size[u] = 1;
    depth[u] = d;
    for (auto nei : adj[u]) if (nei != par) {
        dfs_size(nei, u, d + 1);
        subtree_size[u] += subtree_size[nei];
    }
    for (auto nei : adj[u]) if (nei != par && subtree_size[nei] >= subtree_size[u] / 2) heavyChild[u] = nei;
}


void dfs_label(int u, int par) {
    label[u] = T++;
    // set the point in the segment tree corresponding to u = v[u]
    update(0, maxn, label[u], 0, v[u]);
    parent[0][u] = par;
    if (u == heavyChild[par]) top[u] = top[par];
    else top[u] = u;

    if (heavyChild[u]) dfs_label(heavyChild[u], u);

    for (auto nei : adj[u]) if (nei != par && nei != heavyChild[u]) dfs_label(nei, u); 
}

// lca using binary lifting
int lca(int a, int b) {
    // make a the deeper one
    if (depth[a] < depth[b]) swap(a, b);
    int depthDiff = depth[a] - depth[b];
    int cnt = 0;
    while (depthDiff) {
        if (depthDiff & 1) a = parent[cnt][a];
        depthDiff >>= 1;
        ++cnt;
    }

    if (a == b) return a;

    for (int i = 18; i >= 0; --i) {
        if (parent[i][a] != parent[i][b]) {
            a = parent[i][a];
            b = parent[i][b];
        }
    }

    return parent[0][a];
}

// assume l is the lca, a is a node below
int chain(int l, int a) {
    // climb a up to l
    int res = 0;
    while (depth[top[a]] > depth[l]) {
        // required to avoid TLE: avoids querying the segtree for point queries (recursive segtree is gigaslow)
        if (top[a] == a) {
            res = max(res, v[a]);
            a = parent[0][a];
            continue;
        }
        res = max(res, query(0, maxn, label[top[a]], label[a] + 1, 0));
        a = parent[0][top[a]];
    }
    res = max(res, query(0, maxn, label[l], label[a] + 1, 0));
    return res;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) cin >> v[i];

    int a, b;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    // get the sizes of all the subtrees, as well as all the heavy children, heavyChild == 0 if no heavyChild
    dfs_size(1, 0, 1);
    // label all the nodes, also get the tops of the chains
    dfs_label(1, 0);
    // binary lifting
    for (int i = 1; i < 19; ++i) {
        for (int j = 1; j <= n; ++j) {
            parent[i][j] = parent[i - 1][parent[i - 1][j]];
        }
    }

    int c;
    for (int i = 0; i < q; ++i) {
        cin >> a >> b >> c;
        if (a == 1) {
            v[b] = c;
            update(0, maxn, label[b], 0, c);
        }
        else {
            int l = lca(b, c);
            cout << max(chain(l, b), chain(l, c)) << ' ';
        }
    }
    cout << '\n';


}