#include <bits/stdc++.h>


using namespace std;

int n;
vector<int> adj[200010];


int first[200010];
int second[200010];
// dont technically need this, kept for clarity
int out[200010];

// calculating the distances of the first and second longest paths inside the subtree of node u
// if second longest path uses same node as first, discarded
// (first and second paths dont use common nodes)
int dfs1(int u, int from) {
    int depth = 0;
    for (auto nei : adj[u]) {
        if (nei == from) continue;
        auto child = dfs1(nei, u) + 1;
        if (child > first[u]) {
            second[u] = first[u];
            first[u] = child;
        }
        else if (child > second[u]) {
            second[u] = child;
        }
        depth = max(depth, child);
    }
    return depth;
}

// calculating the distance of the longest path outside the subtree of node u
void dfs(int u, int from) {
    for (auto child : adj[u]) {
        if (child == from) continue;
        if (first[u] == first[child] + 1) {
            out[child] = max(out[u] + 1, second[u] + 1);
        }
        else out[child] = max(out[u] + 1, first[u] + 1);
        dfs(child, u);
    }
}

// max path outside of this subtree is equal to
// if this child is the best path downwards from parent, out[u] = max(out[parent] + 1, second[parent] + 1)
// if this child is not the best path downards from parent, out[u] = max(out[parent] + 1, first[parent] + 1)



int main(void) {
    cin >> n;


    int a, b;
    for (int i = 1; i <= n - 1; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs1(1, -1);
    dfs(1, -1);


    // for (int i = 1; i <= n; ++i) {
    //     cout << out[i] << " ";
    // }
    // cout << "\n";
    // for (int i = 1; i <= n; ++i) {
    //     cout << first[i] << " ";
    // }
    // cout << "\n";
    // for (int i = 1; i <= n; ++i) {
    //     cout << second[i] << " ";
    // }
    // cout << "\n";

    for (int i = 1; i <= n; ++i) {
        cout << max(first[i], out[i]) << " ";
    }

}