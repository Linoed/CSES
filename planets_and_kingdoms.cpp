#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100010];

int pre[100010];
int low[100010];
stack<int> s;
bool act[100010];
int T = 1;
int cc[100010];
int curr = 1;

void dfs(int u) {
    pre[u] = T;
    low[u] = T++;
    act[u] = true;
    s.push(u);

    for (auto nei : adj[u]) {
        if (!pre[nei]) {
            dfs(nei);
            low[u] = min(low[u], low[nei]);
        }
        if (act[nei]) low[u] = min(low[u], low[nei]);
    }
    
    if (low[u] == pre[u]) {
        int node;
        do {
            node = s.top();
            act[node] = false;
            cc[node] = curr;
            s.pop();
        } while (node != u);
        ++curr;
    }
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
    }

    for (int i = 1; i <= n; ++i) {
        if (!pre[i]) dfs(i);
    }
    cout << curr - 1 << '\n';
    for (int i = 1; i <= n; ++i) cout << cc[i] << ' ';
    cout << '\n';
}