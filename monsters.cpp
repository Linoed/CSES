#include <bits/stdc++.h>
using namespace std;

char grid[1010][1010];
bool bad[1010][1010];
bool vis[1010][1010];
char prevC[1010][1010];
pair<int, int> prv[1010][1010];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
char dc[4] = {'U', 'R', 'D', 'L'};


int m, n;

bool valid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m && grid[j][i] != '#';
}

bool finish(int i, int j) {
    return (i == 0 || i == n - 1 || j == 0 || j == m - 1) && grid[j][i] != '#';
}

int main(void) {

    cin >> m >> n;

    queue<pair<pair<int, int>, bool>> q;
    pair<int, int> start;
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            cin >> grid[j][i];
            if (grid[j][i] == 'M') {
                q.push({{i, j}, true});
                bad[j][i] = true;
            }
            else if (grid[j][i] == 'A') {
                start = {i, j};
                vis[j][i] = true;
            }
            
        }
    }

    if (finish(start.first, start.second)) {
        cout << "YES\n0\n";
        return 0;
    }

    q.push({start, false});
    while (!q.empty()) {
        auto& data = q.front();
        int cx = data.first.first;
        int cy = data.first.second;
        bool mon = data.second;
        if (!mon && finish(cx, cy)) {
            cout << "YES\n";
            auto curr = prv[cy][cx];
            string res(1, prevC[cy][cx]);
            while (curr.first != start.first || curr.second != start.second) {
                res.push_back(prevC[curr.second][curr.first]);
                curr = prv[curr.second][curr.first];
            }
            reverse(res.begin(), res.end());
            cout << res.size() << '\n' << res << '\n';
            return 0;
        }
        q.pop();
        for (int dir = 0; dir < 4; ++dir) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            if (valid(nx, ny)) {
                if (mon) {
                    if (bad[ny][nx]) continue;
                    q.push({{nx, ny}, true});
                    bad[ny][nx] = true;
                }
                else {
                    if (vis[ny][nx] || bad[ny][nx]) continue;
                    prevC[ny][nx] = dc[dir];
                    prv[ny][nx] = {cx, cy};
                    q.push({{nx, ny}, false});
                    vis[ny][nx] = true;
                }
            }
        }
    }
    
    cout << "NO\n";


}