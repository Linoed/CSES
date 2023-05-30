#include <bits/stdc++.h>
using namespace std;

struct edge {
    int s, e, w;
};

vector<edge> edges;
vector<int> adj[2510];
vector<int> radj[2510];
long long dist[2510];
bool canEnd[2510];
bool canStart[2510];

int n, m;
void rdfs(int u) {
    canEnd[u] = true;
    for (auto nei : radj[u]) if (!canEnd[nei]) rdfs(nei);
}

void dfs(int u) {
    canStart[u] = true;
    for (auto nei : adj[u]) if (!canStart[nei]) dfs(nei);
}

int main(void) {
    
    cin >> n >> m;

    int a, b, c;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        edges.push_back({a, b, -c});
        adj[a].push_back(b);
        radj[b].push_back(a);
    }

    rdfs(n);
    dfs(1);

    dist[1] = 0;
    for (int i = 2; i <= n; ++i) dist[i] = 1e18;

    for (int i = 0; i < n - 1; ++i) {
        bool relaxed = false;
        for (auto& e : edges) {
            // from e.s to e.e
            if (dist[e.e] > dist[e.s] + e.w) {
                dist[e.e] = dist[e.s] + e.w;
                relaxed = true;
            }
        }
        if (!relaxed) break;
    }

    for (auto& e : edges) {
        if (!canEnd[e.s] || !canEnd[e.e]) continue;
        if (!canStart[e.s] || !canStart[e.e]) continue;
        if (dist[e.e] > dist[e.s] + e.w) {
            cout << "-1\n";
            return 0;
        }
    }

    cout << -dist[n] << '\n';
}