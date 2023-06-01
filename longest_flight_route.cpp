#include <bits/stdc++.h>
using namespace std;


vector<int> adj[100010];
int dp[100010];
int nxt[100010];
int n, m;

void dfs(int u) {
    if (u == n) {
        dp[u] = 1;
        return;
    }
    if (adj[u].empty()) {
        dp[u] = -1;
        return;
    }
    int best = -1;
    for (auto nei : adj[u]) {
        if (!dp[nei]) dfs(nei);
        if (dp[nei] == -1) continue;
        if (dp[nei] + 1 > best) {
            best = dp[nei] + 1;
            nxt[u] = nei;
        }
    }
    dp[u] = best;
}

int main(void) {
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
    }

    dfs(1);

    if (!dp[n]) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    int node = 1;
    vector<int> path;
    while (node != n) {
        path.push_back(node);
        node = nxt[node];
    }
    cout << path.size() + 1 << '\n';
    for (auto x : path) cout << x << ' ';
    cout << n << '\n';

}