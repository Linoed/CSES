#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

vector<int> adj[100010];
int dp[100010];
bool vis[100010];
int n, m;

int modadd(int a, int b) {
    return ((a + b) % MOD + MOD) % MOD;
}

void dfs(int u) {
    vis[u] = true;
    if (u == n) {
        dp[u] = 1;
        return;
    }

    int res = 0;
    for (auto nei : adj[u]) {
        if (!vis[nei]) dfs(nei);
        res = modadd(res, dp[nei]);
    }
    dp[u] = res;
}



int main(void) {
    cin >> n >> m;

    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
    }

    dfs(1);

    cout << dp[1] << '\n';
}