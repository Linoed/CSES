#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

vector<pair<int, int>> adj[100010];
int num[100010];
long long dist[100010];
int mnm[100010];
int mxm[100010];

int modadd(int a, int b) {
    return ((a + b) % MOD + MOD) % MOD;
}

int main(void) {

    int n, m;

    cin >> n >> m;

    int a, b, c;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    for (int i = 2; i <= n; ++i) dist[i] = 1e18;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    num[1] = 1;
    mnm[1] = 1;
    mxm[1] = 1;


    while (!pq.empty()) {
        auto d = pq.top().first;
        auto node = pq.top().second;
        if (node == n) break;
        pq.pop();
        for (auto& nei : adj[node]) {
            if (dist[nei.first] > d + nei.second) {
                pq.push({d + nei.second, nei.first});
                dist[nei.first] = d + nei.second;
                num[nei.first] = num[node];
                mnm[nei.first] = mnm[node] + 1;
                mxm[nei.first] = mxm[node] + 1;
            }
            else if (dist[nei.first] == d + nei.second) {
                num[nei.first] = modadd(num[nei.first], num[node]);
                mnm[nei.first] = min(mnm[nei.first], mnm[node] + 1);
                mxm[nei.first] = max(mxm[nei.first], mxm[node] + 1);
            }
        }
    }

    cout << dist[n] << ' ' << num[n] << ' ' << mnm[n] - 1 << ' ' << mxm[n] - 1 << '\n';

}