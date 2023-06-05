#include <bits/stdc++.h>
using namespace std;

long long res = 0;

int k[100010];
vector<int> adj[100010], cadj[100010];

int pre[100010], low[100010], T = 1, curr = 1;
bool on[100010];
stack<int> s;

long long cc[100010], ccv[100010];

void dfs(int u) {
    pre[u] = T;
    low[u] = T++;
    on[u] = true;
    s.push(u);

    for (auto nei : adj[u]) {
        if (!pre[nei]) {
            dfs(nei);
            low[u] = min(low[u], low[nei]);
        }
        else if (on[nei]) low[u] = min(low[u], low[nei]);
    }

    if (low[u] == pre[u]) {
        int node;
        do {
            node = s.top();
            on[node] = false;
            cc[node] = curr;
            ccv[curr] += k[node];
            s.pop();
        } while (node != u);
        ++curr;
    }
}

bool vis[100010];
long long dp[100010];
long long best = 0;

void dfs2(int u) {
    vis[u] = true;
    long long res = 0;
    for (auto nei : cadj[u]) {
        if (!vis[nei]) dfs2(nei);
        res = max(res, dp[nei]);
    }
    dp[u] = res + ccv[u];
    best = max(best, dp[u]);
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) cin >> k[i];

    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for (int i = 1; i <= n; ++i) if (!pre[i]) dfs(i);

    for (int i = 1; i <= n; ++i) for (auto nei : adj[i]) if (cc[i] != cc[nei]) cadj[cc[i]].push_back(cc[nei]);

    for (int i = 1; i < curr; ++i) if (!vis[i]) dfs2(i);
    cout << best << '\n';
}