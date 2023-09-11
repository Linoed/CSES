#include <bits/stdc++.h>
using namespace std;

int c[200010];
vector<int> adj[200010];
int res[200010];

set<int> dfs(int u, int par) {
    set<int> st;
    st.insert(c[u]);
    for (auto nei : adj[u]) if (nei != par) {
        auto ret = dfs(nei, u);
        // make st the bigger one
        if (ret.size() > st.size()) swap(ret, st);
        for (auto x : ret) st.insert(x);
    }
    res[u] = st.size();
    return st;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;


    for (int i = 1; i <= n; ++i) cin >> c[i];

    int a, b;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, -1);

    for (int i = 1; i <= n; ++i) cout << res[i] << ' ';
    cout << '\n';
}