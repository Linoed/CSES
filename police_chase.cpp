#include <bits/stdc++.h>
using namespace std;

const int maxn = 600;
const int maxe = 5000;

int S, T;

int start[maxn], succ[maxe], to[maxe], cap[maxe], tot;

void add(int u, int v, int c) {
    to[tot] = v;
    cap[tot] = c;
    succ[tot] = start[u];
    start[u] = tot++;

    to[tot] = u;
    cap[tot] = 0;
    succ[tot] = start[v];
    start[v] = tot++;
}

int nextChild[maxn], lvl[maxn];

bool bfs() {
    for (int i = 0; i < maxn; ++i) lvl[i] = -1;
    queue<int> q;
    q.push(S);
    lvl[S] = 0;

    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        nextChild[u] = start[u];
        for (auto e = start[u]; e != -1; e = succ[e]) {
            if (!cap[e] || lvl[to[e]] != -1) continue;
            lvl[to[e]] = lvl[u] + 1;
            q.push(to[e]);
        }
    }

    return lvl[T] != -1;
}

int aug(int u, int cflow) {
    if (u == T) return cflow;

    for (int& e = nextChild[u]; e != -1; e = succ[e]) {
        if (!cap[e] || lvl[to[e]] != lvl[u] + 1) continue;
        int rflow = aug(to[e], min(cflow, cap[e]));
        if (rflow) {
            cap[e] -= rflow;
            cap[e ^ 1] += rflow;
            return rflow;
        }
    }

    lvl[u] = -1; // not technically needed becauase of nextChild
    return 0;
}

bool vis[maxn];

void dfs(int u) {
    vis[u] = true;

    for (int e = start[u]; e != -1; e = succ[e]) {
        if (cap[e] && !vis[to[e]]) dfs(to[e]);
    }
}

vector<pair<int, int>> v;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    S = 1, T = n + 10;

    fill(start, start + 600, -1);
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        v.push_back({a, b});
        add(a, b, 1);
        add(b, a, 1);
    }
    add(S, 1, 1e9);
    add(n, T, 1e9);

    long long flow = 0;
    while (bfs()) {
        for (int z = aug(S, 1e9); z; z = aug(S, 1e9)) flow += z;
    }
    cout << flow << '\n';
    dfs(S);
    for (auto& e : v) if (vis[e.first] ^ vis[e.second]) cout << e.first << ' ' << e.second << '\n';

    
}