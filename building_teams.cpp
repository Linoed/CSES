#include <bits/stdc++.h>


using namespace std;

int n, m;

int color[100010];
vector<int> adj[100010];


bool dfs(int u, int c) {
    color[u] = c;
    for (auto nei : adj[u]) {
        if (color[nei] == c || (!color[nei] && !dfs(nei, c ^ 3))) return false;
    }
    return true;
}

int main(void) {

    cin >> n >> m;


    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; ++i) if (!color[i] && !dfs(i, 1)) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for (int i = 1; i <= n; ++i) cout << color[i] << ' ';
    cout << '\n';

}