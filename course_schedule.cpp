#include <bits/stdc++.h>
using namespace std;


int in[100010];
vector<int> adj[100010];

int main(void) {

    int n, m;
    cin >> n >> m;

    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        in[b]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (!in[i]) q.push(i);
    }

    int tot = 0;
    vector<int> res;
    while (!q.empty()) {
        auto node = q.front();
        res.push_back(node);
        ++tot;
        q.pop();
        for (auto nei : adj[node]) {
            in[nei]--;
            if (!in[nei]) q.push(nei);
        }
    }

    if (tot != n) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    for (auto x : res) cout << x << ' ';
    cout << '\n';
}