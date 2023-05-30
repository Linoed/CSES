#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj[200010];

long long dist[200010];

int main(void) {

    int n, m;
    cin >> n >> m;

    int a, b, c;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[a + 100000].push_back({b + 100000, c});
        adj[a].push_back({b + 100000, c / 2});
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, 1});
    for (int i = 1; i <= n; ++i) {
        dist[i] = 1e18;
        dist[i + 100000] = 1e18;
    }


    while (!pq.empty()) {
        auto d = pq.top().first;
        auto node = pq.top().second;
        pq.pop();
        if (dist[node] != 1e18) continue;
        dist[node] = d;

        for (auto& nei : adj[node]) {
            pq.push({nei.second + d, nei.first});
        }
    }

    cout << dist[n + 100000] << '\n';
}

// cant greedily take lowest price, lowest maximum

// g' graph with normal edges
// g graph with normal edges
// connect g' to g with edges of half size
// forces half edges to be taken only once

// let x be g'
// let x + 100000 be g