#include <bits/stdc++.h>
using namespace std;

const int maxn = 600;
const int maxe = 3000;

int start[maxn], succ[maxe], to[maxe], cap[maxe], tot;

int S, T;

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
    for (int i = 0; i < maxn; ++i) {
        lvl[i] = -1;
        nextChild[i] = start[i];
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
    if (u == T) {
        return cflow;
    }
    
    for (auto& e = nextChild[u]; e != -1; e = succ[e]) {
        if (cap[e] && lvl[to[e]] == lvl[u] + 1) {
            int rf = aug(to[e], min(cflow, cap[e]));
            if (rf) {
                cap[e] -= rf;
                cap[e ^ 1] += rf;
                return rf;
            }
        }
    }
    return 0;
}

vector<int> path;

bool dfs(int u) {
    path.push_back(u);
    if (u == T) return true;

    for (auto e = start[u]; e != -1; e = succ[e]) if (!cap[e] && e % 2 == 0 && dfs(to[e])) {
        cap[e] = 1;
        return true;
    }
    return false;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    S = 1;
    T = n;

    fill(start, start + maxn, -1);

    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        add(a, b, 1);
    }

    int flow = 0;
    vector<vector<int>> res;
    while (bfs()) {
        for (int z = aug(S, 1e9); z; z = aug(S, 1e9)) flow += z;
    }
    cout << flow << '\n';
    for (int i = 0; i < flow; ++i) {
        dfs(S);
        cout << path.size() << '\n';
        for (auto x : path) cout << x << ' ';
        cout << '\n';
        path.clear();
    }
}