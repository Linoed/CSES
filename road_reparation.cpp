#include <bits/stdc++.h>
using namespace std;

struct edge {
    int a, b, c;
};

int par[100010];
int sz[100010];

int find(int u) {
    if (par[u] != u) par[u] = find(par[u]);
    return par[u];
}

void union_sets(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return;

    if (sz[a] > sz[b]) swap(a, b);
    sz[b] += sz[a];
    par[a] = b;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<edge> v(m);
    int a, b, c;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        v[i] = {a, b, c};
    }

    sort(v.begin(), v.end(), [](const edge& a, const edge& b) {
        return a.c < b.c;
    });

    for (int i = 1; i <= n; ++i) {
        par[i] = i;
        sz[i] = 1;
    }

    long long res = 0;
    for (auto& e : v) {
        if (find(e.a) == find(e.b)) continue;
        res += e.c;
        union_sets(e.a, e.b);
    }

    if (sz[find(1)] == n) cout << res << '\n';
    else cout << "IMPOSSIBLE\n";

}