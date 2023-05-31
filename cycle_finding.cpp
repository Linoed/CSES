#include <bits/stdc++.h>
using namespace std;


struct edge {
    int s, e, w;
};

vector<edge> edges;

long long dist[2510];
int from[2510];
bool vis[2510];

int main(void) {

    int n, m;
    cin >> n >> m;

    int a, b, c;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }

    for (int i = 1; i <= n; ++i) dist[i] = 1e18;
    

    for (int i = 0; i < n - 1; ++i) {
        bool relaxed = false;
        for (auto& e : edges) {
            if (dist[e.e] > dist[e.s] + e.w) {
                from[e.e] = e.s;
                dist[e.e] = dist[e.s] + e.w;
                relaxed = true;
            }
        }
        if (!relaxed) break;
    }

    vector<int> cycle;
    for (auto& e : edges) {
        if (dist[e.e] > dist[e.s] + e.w) {
            cout << "YES\n";
            int node = e.e;
            while (!vis[node]) {
                vis[node] = true;
                node = from[node];
            }
            cycle = {node};
            int u = from[node];
            while (u != node) {
                cycle.push_back(u);
                u = from[u];
            }
            reverse(cycle.begin(), cycle.end());
            cout << cycle[cycle.size() - 1] << ' ';
            for (auto x : cycle) cout << x << ' ';
            cout << '\n';
            return 0;
        }
    }


    cout << "NO\n";
}