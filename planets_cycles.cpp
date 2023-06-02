#include <bits/stdc++.h>
using namespace std;

int adj[200010];

bool cycle[200010];
bool vis[200010];
int par[200010];
int sz[200010];
int col[200010];
int depth[200010];

void dfs(int u) {
    col[u] = 1;
    if (col[adj[u]] == 1) {
        int node = u;
        vector<int> path;
        while (node != adj[u]) {
            path.push_back(node);
            node = par[node];
        }
        path.push_back(adj[u]);
        int pathSize = path.size();
        for (auto x : path) {
            cycle[x] = true;
            sz[x] = pathSize;
        }
    }
    else if (!col[adj[u]]) {
        par[adj[u]] = u;
        dfs(adj[u]);
    }
    col[u] = 2;
}

void dfs1(int u) {
    vis[u] = true;
    if (cycle[u]) return;
    if (!vis[adj[u]]) dfs1(adj[u]);
    depth[u] = depth[adj[u]] + 1;
    sz[u] = sz[adj[u]];
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) cin >> adj[i];

    for (int i = 1; i <= n; ++i) if (!col[i]) dfs(i);
    for (int i = 1; i <= n; ++i) if (!vis[i]) dfs1(i);

    for (int i = 1; i <= n; ++i) {
        cout << depth[i] + sz[i] << ' ';
    }
    cout << '\n';

}