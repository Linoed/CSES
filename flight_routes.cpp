#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj[100010];
int cnt[100010];

int main(void) {

    int n, m, k;
    cin >> n >> m >> k;

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
        if (cnt[node] >= k) continue;
        cnt[node]++;
        if (node == n) {
            cout << d << ' ';
        }
        for (auto& nei : adj[node]) {
            pq.push({d + nei.second, nei.first});
        }
    }
    cout << '\n';
}
