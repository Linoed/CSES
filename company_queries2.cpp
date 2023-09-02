#include <bits/stdc++.h>
using namespace std;

int par[19][200010];
int depth[200010];
vector<int> adj[200010];

void dfs(int u, int d) {
    depth[u] = d;
    for (auto nei : adj[u]) dfs(nei, d + 1);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    int e;
    for (int i = 2; i <= n; ++i) {
        cin >> e;
        par[0][i] = e;
        adj[e].push_back(i);
    }

    dfs(1, 0);

    for (int i = 1; i < 19; ++i) {
        for (int j = 1; j <= n; ++j) par[i][j] = par[i - 1][par[i - 1][j]];
    }

    int a, b;
    for (int i = 0; i < q; ++i) {
        cin >> a >> b;
        // make a the one with highest depth
        if (depth[b] > depth[a]) swap(a, b);
        int depthDiff = depth[a] - depth[b];
        int cnt = 0;
        while (depthDiff) {
            if (depthDiff & 1) a = par[cnt][a];
            ++cnt;
            depthDiff >>= 1;
        }

        if (a == b) {
            cout << a << '\n';
            continue;
        }

        // lift until par[0][a] == par[0][b], then return par[0][a]
        int biggest = 18;
        while (par[0][a] != par[0][b]) {
            if (par[biggest][a] != par[biggest][b]) {
                a = par[biggest][a];
                b = par[biggest][b];
            }
            --biggest;
        }
        cout << par[0][a] << '\n';
    }

}