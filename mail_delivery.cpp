#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj[100010];
bool used[200010];


vector<int> res;

void dfs(int u) {
    while (!adj[u].empty()) {
        int e = adj[u].back().second;
        int v = adj[u].back().first;
        adj[u].pop_back();
        if (used[e]) continue;
        used[e] = true;
        dfs(v);
    }
    res.push_back(u);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
    }

    for (int i = 1; i <= n; ++i) if (adj[i].size() & 1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    if (adj[1].empty()) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    dfs(1);
    if (res.size() != m + 1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    for (auto x : res) cout << x << ' ';
    cout << '\n';
}