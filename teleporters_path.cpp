#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100010];
vector<int> res;

int out[200010];
int in[200010];

void dfs(int u) {
    while (!adj[u].empty()) {
        int v = adj[u].back();
        adj[u].pop_back();
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
        adj[a].push_back(b);
        in[b]++;
        out[a]++;
    }

    if (out[1] - in[1] != 1 || in[n] - out[n] != 1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    for (int i = 2; i < n; ++i) if (in[i] != out[i]) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    dfs(1);
    if (res.size() != m + 1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    reverse(res.begin(), res.end());
    for (auto x : res) cout << x << ' ';
    cout << '\n';
}