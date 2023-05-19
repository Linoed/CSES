#include <bits/stdc++.h>

using namespace std;

int m, n;

char grid[1010][1010];
bool vis[1010][1010];

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {-1, 0, 1, 0};

bool valid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m && !vis[j][i] && grid[j][i] == '.';
}

void dfs(int i, int j) {
    vis[j][i] = true;
    for (int dir = 0; dir < 4; ++dir) {
        int nx = i + dx[dir];
        int ny = j + dy[dir];
        if (valid(nx, ny)) dfs(nx, ny);
    }
}

int main(void) {

    cin >> m >> n;

    for (int j = 0; j < m; ++j) for (int i = 0; i < n; ++i) cin >> grid[j][i];
    int res = 0;
    for (int j = 0; j < m; ++j) for (int i = 0; i < n; ++i) {
        if (!vis[j][i] && grid[j][i] == '.') {
            dfs(i, j);
            ++res;
        }
    }
    cout << res << '\n';
}