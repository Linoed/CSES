#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200010];
int res[200010];

void dfs(int u) {
    int v = 1;
    for (auto nei : adj[u]) {
        if (!res[nei]) dfs(nei);
        v += res[nei];
    }
    res[u] = v;
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;


    int x;
    for (int i = 2; i <= n; ++i) {
        cin >> x;
        adj[x].push_back(i);
    }

    dfs(1);

    for (int i = 1; i <= n; ++i) cout << res[i] - 1 << ' ';
    cout << '\n';
}