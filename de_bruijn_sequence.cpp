#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj[1 << 16];

vector<int> res;
bool used[1 << 17];

int n;

void dfs(int u) {
    while (!adj[u].empty()) {
        auto e = adj[u].back().second;
        auto v = adj[u].back().first;
        adj[u].pop_back();
        if (used[e]) continue;
        used[e] = true;
        dfs(v);
    }
    res.push_back(u & 1);
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    if (n == 1) {
        cout << "10\n";
        return 0;
    }
    // each substring is connected to another substring
    // by adding 1 or 0 to the right

    int e = 0;
    int mask = (1 << (n - 1)) - 1;

    for (int i = 0; i < (1 << (n - 1)); ++i) {
        // add an edge by adding a 1
        // add an edge by adding a 0
        adj[i].push_back({((i << 1) & mask) | 1, e++});
        adj[i].push_back({((i << 1) & mask), e++});
    }

    dfs(0);
    
    reverse(res.begin(), res.end());
    for (int i = 0; i < n - 2; ++i) cout << '0';
    for (auto x : res) cout << x;
    cout << '\n';

}