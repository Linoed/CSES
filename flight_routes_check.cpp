#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100010];

int pre[100010];
int low[100010];
int T = 1;
bool active[100010];
stack<int> s;

int found = 0;

void dfs(int u) {
    pre[u] = T;
    low[u] = T++;
    active[u] = true;
    s.push(u);

    for (auto nei : adj[u]) {
        if (!pre[nei]) {
            dfs(nei);
            low[u] = min(low[u], low[nei]);
        }
        else if (active[nei]) {
            low[u] = min(low[u], low[nei]);
        }
    }

    if (low[u] == pre[u]) {
        int node;
        if (!found) found = s.top();
        else {
            cout << "NO\n";
            cout << found << ' ' << s.top() << '\n';
            exit(0);
        }
        do {
            node = s.top();
            active[node] = false;
            s.pop();
        } while (node != u);
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

    cout << "YES\n";
}