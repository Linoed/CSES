#include <bits/stdc++.h>

using namespace std;


bool vis[100010];
unordered_set<int> adj[100010];

vector<int> path;

bool dfs(int u, int prev) {
    vis[u] = true;
    for (auto nei : adj[u]) {
        if (nei == prev) continue;
        if (vis[nei] || dfs(nei, u)) {
            path.push_back(nei);
            return true;
        }
    }
    return false;
}

int main(void) {

    int n, m;
    cin >> n >> m;

    int a, b;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    for (int i = 1; i <= n; ++i) {
        if (!vis[i] && dfs(i, -1)) {
            vector<int> res = {path[0]};
            int idx = 1;
            while (idx < path.size() && path[idx] != path[0]) res.push_back(path[idx++]);
            res.push_back(res[0]);
            cout << res.size() << '\n';
            for (auto x : res) cout << x << ' ';
            cout << '\n';
            return 0;
        }
    }
    cout << "IMPOSSIBLE\n";
}