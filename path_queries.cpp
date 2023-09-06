#include <bits/stdc++.h>
using namespace std;

int v[200010], cv[200010];
vector<int> adj[200010];
int pre[200010], post[200010];
int curr = 1;

long long bit[200010];

void add(int x, int val) {
    for (int i = x; i < 200010; i += (i & -i)) bit[i] += val;
}

void addrange(int l, int r, int val) {
    add(l, val);
    add(r + 1, -val);
}

long long query(int x) {
    long long res = 0;
    for (int i = x; i > 0; i -= (i & -i)) res += bit[i];
    return res;
}

void update(int x, int val) {
    int addend = val - cv[x];
    addrange(pre[x], post[x] - 1, addend);
    cv[x] = val;
}

void dfs(int u, int par) {
    pre[u] = curr++;

    for (auto nei : adj[u]) if (nei != par) dfs(nei, u);

    post[u] = curr;
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) cin >> v[i];

    int a, b;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, -1);

    for (int i = 1; i <= n; ++i) update(i, v[i]);

    int s, x;
    for (int i = 0; i < q; ++i) {
        cin >> a >> s;
        if (a == 1) {
            cin >> x;
            update(s, x);
        }
        else {
            cout << query(pre[s]) << '\n';
        }
    }

    // when increasing value by x, update the entire subtree by x
    // when asking node n, ask the point n
    // range update, point query



}