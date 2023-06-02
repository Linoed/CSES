#include <bits/stdc++.h>
using namespace std;

int adj[200010];
vector<int> radj[200010];
// cc of the node
int cc[200010];
// idx of the node in its cycle
int idx[200010];
// size of the cycle that the node is part of
int sz[200010];
int par[200010];
int col[200010];
int curr = 0;

int dp[32][200010];
bool vis[200010];
int depth[200010];

void dfs1(int u) {
    cc[u] = curr;
    if (!cc[adj[u]]) dfs1(adj[u]);
    for (auto nei : radj[u]) if (!cc[nei]) dfs1(nei);
}

void dfs2(int u) {
    vis[u] = true;
    if (sz[u]) return;

    if (!vis[adj[u]]) dfs2(adj[u]);
    depth[u] = depth[adj[u]] + 1;
}

void dfs(int u) {
    col[u] = 1;
    if (col[adj[u]] == 1) {
        int end = adj[u];
        int node = u;
        vector<int> path;
        while (node != end) {
            path.push_back(node);
            node = par[node];
        }
        path.push_back(end);
        reverse(path.begin(), path.end());
        int pathSize = path.size();
        for (int i = 0; i < pathSize; ++i) {
            sz[path[i]] = pathSize;
            idx[path[i]] = i;
        }
        col[u] = 2;
        return;
    }
    else if (!col[adj[u]]) {
        par[adj[u]] = u;
        dfs(adj[u]);
    }
    col[u] = 2;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;

    int t;
    for (int i = 1; i <= n; ++i) {
        cin >> t;
        adj[i] = t;
        dp[0][i] = t;
        radj[t].push_back(i);
    }

    // get the ccs
    for (int i = 1; i <= n; ++i) {
        if (!cc[i]) {
            ++curr;
            dfs1(i);
        }
    }

    for (int i = 1; i <= n; ++i) if (!col[i]) dfs(i);

    for (int i = 1; i <= n; ++i) if (!vis[i]) dfs2(i);

    for (int j = 1; j < 32; ++j) {
        for (int i = 1; i <= n; ++i) {
            dp[j][i] = dp[j - 1][dp[j - 1][i]];
        }
    }

    int a, b;
    for (int i = 0; i < q; ++i) {
        cin >> a >> b;
        if ((cc[a] != cc[b]) || (sz[a] && !sz[b])) {
            cout << "-1\n";
            continue;
        }
        if (sz[a] && sz[b]) {
            if (idx[b] >= idx[a]) {
                cout << idx[b] - idx[a] << '\n';
            }
            else {
                cout << sz[a] - (idx[a] - idx[b]) << '\n';
            }
            continue;
        }
        // a on tree, b on cycle
        if (sz[b] && !sz[a]) {
            int tmp = depth[a];
            int d = depth[a];

            for (int i = 0; i < 32; ++i) {
                if (tmp & 1) a = dp[i][a];
                tmp >>= 1;
            }

            if (idx[b] >= idx[a]) {
                cout << idx[b] - idx[a] + d << '\n';
            }
            else {
                cout << sz[a] - (idx[a] - idx[b]) + d << '\n';
            }
            continue;
        }
        // both on tree
        if (depth[a] < depth[b]) {
            cout << "-1\n";
            continue;
        }
        int depthDiff = depth[a] - depth[b];
        int d = depthDiff;
        
        for (int i = 0; i < 32; ++i) {
            if (depthDiff & 1) a = dp[i][a];
            depthDiff >>= 1;
        }
        if (a == b) cout << d << '\n';
        else cout << "-1\n";
    }

}


// if part of diff cc
// -1

// if part of same cycle (use cc as there's at most 1 cycle in cc)
// just compute difference of indices

// both not part of cycle
// binary lift until depth from cycle is same
// check equal node, if not -1

// one part of cycle, one not
// if from part of cycle, -1
// else get the tree root and compute difference of indices
