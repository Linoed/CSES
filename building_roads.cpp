#include <bits/stdc++.h>

using namespace std;

int n, m;


bool vis[100010];
vector<int> adj[100010];



void dfs(int u) {
    vis[u] = true;
    for (auto nei : adj[u]) if (!vis[nei]) dfs(nei);
}

int main(void) {

    cin >> n >> m;

    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> bad;
    for (int i = 1; i <= n; ++i) if (!vis[i]) {
        dfs(i);
        bad.push_back(i);
    }

    cout << (int) bad.size() - 1 << '\n';
    for (int i = 1; i < bad.size(); ++i) cout << "1 " << bad[i] << '\n';
}