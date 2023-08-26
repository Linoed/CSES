// #include <bits/stdc++.h>
// using namespace std;

// vector<int> adj[200010];

// int maxD = 0, maxNode;

// void dfs(int u, int depth, int par) {
//     if (depth > maxD) {
//         maxD = depth;
//         maxNode = u;
//     }

//     for (auto nei : adj[u]) {
//         if (nei == par) continue;
//         dfs(nei, depth + 1, u);
//     }
// }

// int main(void) {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int n;
//     cin >> n;

//     int a, b;
//     for (int i = 0; i < n - 1; ++i) {
//         cin >> a >> b;
//         adj[a].push_back(b);
//         adj[b].push_back(a);
//     }

//     dfs(1, 0, -1);
//     maxD = 0;
//     dfs(maxNode, 0, -1);
//     cout << maxD << '\n';
// }

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200010];
int first[200010], second[200010];

void dfs(int u, int par) {
    for (auto nei : adj[u]) if (nei != par) dfs(nei, u);

    for (auto nei : adj[u]) if (nei != par) {
        auto dist = first[nei] + 1;
        if (dist >= first[u]) {
            second[u] = first[u];
            first[u] = dist;
        }
        else if (dist > second[u]) {
            second[u] = dist;
        }
    }
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int a, b;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, -1);

    int res = 0;
    for (int i = 1; i <= n; ++i) res = max(res, first[i] + second[i]);
    cout << res << '\n';
}
