#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200020];

// horrible idea, use (x << 1) | 1
int notNode(int x) {
    if (x > 100010) return x - 100010;
    else return x + 100010;
}

int pre[200010];
int low[200010];
int T = 1;
int curr = 1;
stack<int> s;
bool onStack[200010];
int scc[200010];

char res[100010];

void dfs(int u) {
    pre[u] = T;
    low[u] = T++;
    s.push(u);
    onStack[u] = true;
    for (auto nei : adj[u]) {
        if (!pre[nei]) {
            dfs(nei);
            low[u] = min(low[u], low[nei]);
        }
        else if (onStack[nei]) low[u] = min(low[u], low[nei]);
    }

    if (low[u] == pre[u]) {
        int node;
        do {
            node = s.top();
            onStack[node] = false;
            scc[node] = curr;
            s.pop();
        } while (node != u);
        ++curr;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    char a, c;
    int b, d;

    for (int i = 0; i < n; ++i) {
        cin >> a >> b >> c >> d;
        if (a == '-') b += 100010;
        if (c == '-') d += 100010;

        adj[notNode(d)].push_back(b);
        adj[notNode(b)].push_back(d);
    }

    for (int i = 1; i <= m; ++i) {
        if (!pre[i]) dfs(i);
        if (!pre[notNode(i)]) dfs(notNode(i));
    }


    for (int i = 1; i <= m; ++i) {
        if (scc[i] == scc[notNode(i)]) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        if (scc[i] < scc[notNode(i)]) res[i] = '+';
        else res[i] = '-';
    }

    for (int i = 1; i <= m; ++i) cout << res[i] << ' ';
    cout << '\n';
}


// ~a v b -> a -> b, ~b -> ~a
// a v b -> ~a -> b, ~b -> a