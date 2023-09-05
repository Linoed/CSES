#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200010];
int par[19][200010], depth[200010];
int res[200010];

void dfs(int u, int parent, int d) {
    par[0][u] = parent;
    depth[u] = d;
    for (auto nei : adj[u]) if (nei != parent) dfs(nei, u, d + 1);
}

int lca(int a, int b) {
    // make a the lower one
    if (depth[a] < depth[b]) swap(a, b);

    int depthDiff = depth[a] - depth[b];
    int cnt = 0;
    while (depthDiff) {
        if (depthDiff & 1) a = par[cnt][a];
        depthDiff >>= 1;
        ++cnt;
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

int dfs2(int u, int parent) {
    for (auto nei : adj[u]) if (nei != parent) res[u] += dfs2(nei, u);
    return res[u];
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int a, b;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0, 0);

    for (int j = 1; j < 19; ++j) {
        for (int i = 1; i <= n; ++i) {
            par[j][i] = par[j - 1][par[j - 1][i]];
        }
    }

    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        // make a the higher one
        if (depth[a] > depth[b]) swap(a, b);
        int l = lca(a, b);
        if (a == l) {
            --res[par[0][a]];
            ++res[b];
        }
        else {
            ++res[a];
            ++res[b];
            res[par[0][l]]--;
            res[l]--;
        }
    }

    dfs2(1, -1);

    for (int i = 1; i <= n; ++i) cout << res[i] << ' ';
    cout << '\n';
}