#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100010];

int endNode = 0;
int par[100010];
int vis[100010];

void dfs(int u) {
    vis[u] = 1;

    for (auto nei : adj[u]) {
        if (vis[nei] == 1) {
            vector<int> path = {nei};
            while (u != nei) {
                path.push_back(u);
                u = par[u];
            }
            path.push_back(nei);
            reverse(path.begin(), path.end());
            cout << path.size() << '\n';
            for (auto x : path) cout << x << ' ';
            cout << '\n';
            exit(0);
        }
        else if (!vis[nei]) {
            par[nei] = u;
            dfs(nei);
        }
    }

    vis[u] = 2;
}


int main(void) {
    int n, m;
    cin >> n >> m;

    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) dfs(i);
    }
    cout << "IMPOSSIBLE\n";
}