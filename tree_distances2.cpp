#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200010];

int n;
long long in[200010], sz[200010], out[200010];

void dfs1(int u, int par) {
    sz[u] = 1;
    for (auto nei : adj[u]) if (nei != par) {
        dfs1(nei, u);
        in[u] += in[nei] + sz[nei];
        sz[u] += sz[nei];
    }
}

void dfs2(int u, int par) {
    if (par != -1) {
        out[u] = out[par] + in[par] - in[u] + n - 2 * sz[u];
    }
    for (auto nei : adj[u]) if (nei != par) dfs2(nei, u);
}

//          take all of outside parent  | take all of inside parent except us
// out[u] = out[par] + n - size[par] + 1 + in[par] - in[u] - size[u] + size[par] - size[u] - 1
//        = out[par] + n + in[par] - in[u] - 2 * size[u]

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

    dfs1(1, -1);
    dfs2(1, -1);

    for (int i = 1; i <= n; ++i) cout << in[i] + out[i] << ' ';
    cout << '\n';

}