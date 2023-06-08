#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
const int maxe = 200010;

int S, T;

int start[maxn], succ[maxe], to[maxe], tot;
// edge from S -> 1 and n -> T can be 64 bit ints
long long cap[maxe];

void add(int u, int v, long long c) {
    cap[tot] = c;
    to[tot] = v;
    succ[tot] = start[u];
    start[u] = tot++;

    cap[tot] = 0;
    to[tot] = u;
    succ[tot] = start[v];
    start[v] = tot++;
}

int lvl[maxn], nextChild[maxn];

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

int aug(int u, long long cflow) {
    if (u == T) return cflow;

    for (int& e = nextChild[u]; e != -1; e = succ[e]) {
        if (!cap[e] || lvl[to[e]] != lvl[u] + 1) continue;
        long long rf = aug(to[e], min(cflow, cap[e]));
        if (rf) {
            cap[e] -= rf;
            cap[e ^ 1] += rf;
            return rf;
        }
    }

    lvl[u] = -1;
    return 0;
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    S = 0;
    T = n + 10;

    fill(start, start + 520, -1);

    int a, b, c;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        add(a, b, c);
    }
    add(S, 1, 1e18);
    add(n, T, 1e18);

    long long flow = 0;
    while (bfs()) {
        for (int z = aug(S, 1e18); z != 0; z = aug(S, 1e18)) flow += z;
    }
    cout << flow << '\n';
}