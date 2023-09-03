#include <bits/stdc++.h>
using namespace std;

int par[19][200010];
int depth[200010];

vector<int> adj[200010];

void dfs(int u, int parent, int d) {
    depth[u] = d;
    par[0][u] = parent;
    for (auto nei : adj[u]) if (nei != parent) dfs(nei, u, d + 1);
}

int lca(int a, int b) {
    // make a the lower one
    if (depth[a] < depth[b]) swap(a, b);

    int depthDiff = depth[a] - depth[b];
    int cnt = 0;
    while (depthDiff) {
        if (depthDiff & 1) a = par[cnt][a];
        ++cnt;
        depthDiff >>= 1;
    }

    if (a == b) return a;
    for (int i = 18; i >= 0; --i) {
        if (par[i][a] != par[i][b]) {
            a = par[i][a];
            b = par[i][b];
        }
    }
    return par[0][a];
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    int a, b;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0, 0);

    for (int i = 1; i < 19; ++i) {
        for (int j = 1; j <= n; ++j) {
            par[i][j] = par[i - 1][par[i - 1][j]];
        }
    }

    for (int i = 0; i < q; ++i) {
        cin >> a >> b;
        int node = lca(a, b);
        if (node == a) {
            cout << depth[b] - depth[a] << '\n';
        }
        else if (node == b) {
            cout << depth[a] - depth[b] << '\n';
        }
        else {
            cout << depth[a] + depth[b] - 2 * depth[node] << '\n';
        }
    }

}