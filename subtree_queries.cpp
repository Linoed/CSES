#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200010];

int v[200010];
long long bit[200010];
int pre[200010], post[200010];
int curr = 1;

long long prefix(int x) {
    long long res = 0;
    for (int i = x; i > 0; i -= (i & -i)) res += bit[i];
    return res;
}

long long query(int l, int r) {
    return prefix(r) - prefix(l - 1);
}

void add(int x, int val) {
    for (int i = x; i < 200010; i += (i & -i)) bit[i] += val;
}

void update(int x, int val) {
    int addend = val - query(x, x);
    add(x, addend);
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
    int x;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
    }

    int a, b;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, -1);
    for (int i = 1; i <= n; ++i) add(pre[i], v[i]);

    int qry, s;
    for (int i = 0; i < q; ++i) {
        cin >> qry >> s;
        if (qry == 1) {
            cin >> x;
            update(pre[s], x);
        }
        else {
            cout << query(pre[s], post[s] - 1) << '\n';
        }
    }

}


// query range sum
// update point