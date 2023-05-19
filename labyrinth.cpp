#include <bits/stdc++.h>

using namespace std;


const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {-1, 0, 1, 0};
const char dc[4] = {'U', 'R', 'D', 'L'};
int m, n;

char grid[1010][1010];
char prvc[1010][1010];
pair<int, int> prv[1010][1010];
bool vis[1010][1010];


bool valid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m && !vis[j][i] && grid[j][i] != '#';
}


int main(void) {

    
    cin >> m >> n;

    pair<int, int> start;
    pair<int, int> end;

    for (int j = 0; j < m; ++j) for (int i = 0; i < n; ++i) {
        cin >> grid[j][i];
        if (grid[j][i] == 'A') start = {i, j};
        else if (grid[j][i] == 'B') end = {i, j};
    }

    queue<pair<int, int>> q;
    q.push(start);
    vis[start.second][start.first] = true;

    while (!q.empty()) {
        auto x = q.front().first;
        auto y = q.front().second;
        q.pop();

        if (x == end.first && y == end.second) break;
        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (valid(nx, ny)) {
                prv[ny][nx] = {x, y};
                prvc[ny][nx] = dc[dir];
                vis[ny][nx] = true;
                q.push({nx, ny});
            }
        }
    }

    if (!vis[end.second][end.first]) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";

    int x = end.first;
    int y = end.second;
    string res;
    while (true) {
        if (x == start.first && y == start.second) break;
        res += prvc[y][x];
        int nx = prv[y][x].first;
        int ny = prv[y][x].second;
        x = nx;
        y = ny;
    }
    reverse(res.begin(), res.end());
    cout << res.size() << '\n';
    cout << res << '\n';

}