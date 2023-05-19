#include <bits/stdc++.h>

using namespace std;

int n, m;

bool vis[100010];
int prv[100010];
vector<int> adj[100010];



int main(void) {

    cin >> n >> m;

    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    vis[1] = true;
    int lvl = 0;
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; ++i) {
            auto node = q.front();
            q.pop();
            if (node == n) break;
            
            for (auto nei : adj[node]) if (!vis[nei]) {
                q.push(nei);
                vis[nei] = true;
                prv[nei] = node;
            }
        }
        ++lvl;
    }

    if (!vis[n]) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    
    vector<int> res;
    int idx = n;
    while (true) {
        res.push_back(idx);
        if (idx == 1) break;
        idx = prv[idx];
    }
    cout << res.size() << '\n';
    for (auto it = res.rbegin(); it != res.rend(); ++it) cout << *it << ' ';
    cout << '\n';
}