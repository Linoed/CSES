// failed attempt at High Score (finding max path in possibly cyclic digraph is NP-hard)
// came up with a cool approach to find positive cycles so will keep it
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj[2510];
vector<int> rev[2510];
bool revVis[2510];
int val[2510];
int col[2510];
bool vis[2510];

int n, m;


void revdfs(int u) {
    revVis[u] = true;
    for (auto nei : rev[u]) if (!revVis[nei]) revdfs(nei);
}

bool cdfs(int u, int sum) {
    col[u] = 1;
    val[u] = sum;
    for (auto& nei : adj[u]) {
        if (!revVis[nei.first]) continue;
        if (col[nei.first] == 1 && sum + nei.second - val[nei.first] > 0) {
            return true;
        }
        else if (col[nei.first] == 0 && cdfs(nei.first, sum + nei.second)) return true; 
    }
    col[u] = 2;
    return false;
}

// int dfs(int u)


int main(void) {

    cin >> n >> m;


    int a, b, c;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        rev[b].push_back(a);
    }

    // get all of the nodes that can reach the end
    revdfs(n);

    if (cdfs(1, 0)) {
        cout << "-1\n";
        return 0;
    }
    // find positive cycles in the new filtered graph
}