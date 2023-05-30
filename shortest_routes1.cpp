#include <bits/stdc++.h>
using namespace std;

long long dist[100010];
bool vis[100010];
vector<pair<int, int>> adj[100010];

int main(void) {
    int n, m;
    cin >> n >> m;

    int a, b, c;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto d = pq.top().first;
        auto node = pq.top().second;
        pq.pop();
        if (vis[node]) continue;
        vis[node] = true;
        dist[node] = d;
        for (auto& nei : adj[node]) {
            pq.push({d + nei.second, nei.first});
        }
    }

    for (int i = 1; i <= n; ++i) cout << dist[i] << ' ';
    cout << '\n';
}