#include <bits/stdc++.h>
using namespace std;

const int maxn = 1100;
const int maxe = 10000;

int start[maxn], succ[maxe], to[maxe], cap[maxe], tot;

int S, T;

void add(int u, int v, int c) {
    cap[tot] = c;
    to[tot] = v;
    succ[tot] = start[u];
    start[u] = tot++;

    cap[tot] = 0;
    to[tot] = u;
    succ[tot] = start[v];
    start[v] = tot++;
}

int nextChild[maxn], lvl[maxn];

bool bfs() {
    for (int i = 0; i < maxn; ++i) {
        nextChild[i] = start[i];
        lvl[i] = -1;
    }

    queue<int> q;
    q.push(S);
    lvl[S] = 0;
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        for (auto e = start[u]; e != -1; e = succ[e]) {
            if (cap[e] && lvl[to[e]] == -1) {
                lvl[to[e]] = lvl[u] + 1;
                q.push(to[e]);
            }
        }
    }
    return lvl[T] != -1;
}

int aug(int u, int cflow) {
    if (u == T) return cflow;

    for (auto& e = nextChild[u]; e != -1; e = succ[e]) {
        if (cap[e] && lvl[to[e]] == lvl[u] + 1) {
            int rflow = aug(to[e], min(cflow, cap[e]));
            if (rflow) {
                cap[e] -= rflow;
                cap[e ^ 1] += rflow;
                return rflow;
            }
        }
    }

    return 0;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    fill(start, start + maxn, -1);

    S = 0;
    T = 1010;

    int a, b;
    for (int i = 0; i < k; ++i) {
        cin >> a >> b;
        add(a, b + 500, 1);
    }

    for (int i = 1; i <= n; ++i) add(S, i, 1);
    for (int i = 1; i <= m; ++i) add(i + 500, T, 1);

    int flow = 0;
    while (bfs()) {
        for (int z = aug(S, 1e9); z; z = aug(S, 1e9)) flow += z;
    }
    cout << flow << '\n';

    for (int e = 0; e < k; ++e) {
        if (!cap[2 * e]) cout << to[(2 * e) ^ 1] << ' ' << to[2 * e] - 500 << '\n';
    }
}