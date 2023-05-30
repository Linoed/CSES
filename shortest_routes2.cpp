#include <bits/stdc++.h>
using namespace std;


long long dist[510][510];

unordered_map<int, unordered_map<int, int>> g;

int main(void) {

    int n, m, q;
    cin >> n >> m >> q;

    

    int a, b, c;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;

        if (g[a][b]) {
            g[a][b] = min(g[a][b], c);
            g[b][a] = min(g[b][a], c);
        }
        else {
            g[a][b] = c;
            g[b][a] = c;
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (g[i][j]) dist[i][j] = g[i][j];
            else dist[i][j] = 1e18;
        }
    }

    for (int i = 1; i <= n; ++i) dist[i][i] = 0;
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= n; ++k) {
                if (dist[j][i] + dist[i][k] < dist[j][k]) dist[j][k] = dist[j][i] + dist[i][k];
            }
        }
    }

    


    for (int i = 0; i < q; ++i) {
        cin >> a >> b;
        cout << (dist[a][b] == 1e18 ? -1 : dist[a][b]) << '\n';
    }

}



// dp[i][j][k] shortest distance between j and k using only first i nodes as intermediaries
