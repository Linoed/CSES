// #include <bits/stdc++.h>
// using namespace std;

// int in[200010];
// bool vis[200010];
// bool taken[200010];
// vector<int> adj[200010];

// int res = 0;

// void dfs(int u) {
//     vis[u] = true;
//     for (auto nei : adj[u]) if (!vis[nei]) {
//         dfs(nei);
//         if (!taken[u] && !taken[nei]) {
//             ++res;
//             taken[u] = true;
//             taken[nei] = true;
//         }
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
//         in[a]++;
//         in[b]++;
//     }

//     for (int i = 1; i <= n; ++i) if (in[i] == 1) {
//         dfs(i);
//         break;
//     }

//     cout << res << '\n';


// }


#include <bits/stdc++.h>
using namespace std;


vector<int> adj[200010];
int take[200010];
int notake[200010];

void dfs(int u, int par) {
    for (auto nei : adj[u]) {
        if (nei == par) continue;
        dfs(nei, u);
        notake[u] += max(notake[nei], take[nei]);
    }

    for (auto nei : adj[u]) {
        if (nei == par) continue;
        // take will take edge u->nei, then notake nei, and additionally max(notake, take) for all but nei
        // max(notake, take) for all == notake[u]
        // max(notake, take) for all but nei == notake[u] - max(notake[nei], take[nei])
        take[u] = max(take[u], notake[nei] + 1 + notake[u] - max(notake[nei], take[nei]));
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
    for (int i = 1; i <= n; ++i) {
        // cout << take[i] << ' ' << notake[i] << '\n';
        res = max({res, take[i], notake[i]});
    }
    cout << res << '\n';

}