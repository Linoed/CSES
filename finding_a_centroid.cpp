#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;

vector<int> adj[maxn];
int sz[maxn];
int res;

int n;

void dfs_size(int u, int par) {
    sz[u] = 1;
    for (auto nei : adj[u]) if (nei != par) {
        dfs_size(nei, u);
        sz[u] += sz[nei];
    }
}

void dfs(int u, int par) {
    int outward_size = n - sz[u];
    if (outward_size <= n / 2) {
        // check if the inward sizes are good too
        bool bad = false;
        for (auto nei : adj[u]) if (nei != par && sz[nei] > n / 2) bad = true;

        if (!bad) res = u;
    }

    for (auto nei : adj[u]) if (nei != par) dfs(nei, u);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    int a, b;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs_size(1, -1);
    dfs(1, -1);

    cout << res << '\n';

}