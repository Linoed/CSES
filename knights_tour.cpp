#include <bits/stdc++.h>
using namespace std;


int vis[8][8];

int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

bool valid(int i, int j) {
    return i >= 0 && i < 8 && j >= 0 && j < 8 && !vis[j][i];
}

int options(int i, int j) {
    int res = 0;
    for (int dir = 0; dir < 8; ++dir) {
        int nx = i + dx[dir];
        int ny = j + dy[dir];
        if (valid(nx, ny)) ++res;
    }
    return res;
}

void dfs(int i, int j, int x) {
    vis[j][i] = x;
    if (x == 64) {
        for (int j = 0; j < 8; ++j) {
            for (int i = 0; i < 8; ++i) cout << vis[j][i] << ' ';
            cout << '\n';
        }
        exit(0);
    }

    vector<pair<int, int>> choices;
    for (int dir = 0; dir < 8; ++dir) {
        int nx = i + dx[dir];
        int ny = j + dy[dir];
        if (valid(nx, ny)) {
            choices.push_back({options(nx, ny), dir});
        }
    }

    sort(choices.begin(), choices.end());

    for (auto& choice : choices) {
        int nx = i + dx[choice.second];
        int ny = j + dy[choice.second];
        dfs(nx, ny, x + 1);
    }

    vis[j][i] = 0;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y;
    cin >> x >> y;
    dfs(x - 1, y - 1, 1);

}