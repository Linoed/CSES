#include <bits/stdc++.h>
using namespace std;

int cc;
int best = 1;

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
    best = max(best, sz[b]);
    --cc;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    cc = n;
    for (int i = 1; i <= n; ++i) {
        par[i] = i;
        sz[i] = 1;
    }

    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        union_sets(a, b);
        cout << cc << ' ' << best << '\n';
    }


}