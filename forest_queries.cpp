#include <bits/stdc++.h>
using namespace std;

char grid[1010][1010];

int pre[1010][1010];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < n; ++i) {
            cin >> grid[j][i];
        }
    }

    if (grid[0][0] == '*') pre[0][0] = 1;

    for (int i = 1; i < n; ++i) pre[0][i] = pre[0][i - 1] + (grid[0][i] == '*' ? 1 : 0);

    for (int j = 1; j < n; ++j) {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if (grid[j][i] == '*') ++sum;
            pre[j][i] = sum + pre[j - 1][i];
        }
    }

    int y1, x1, y2, x2;
    for (int i = 0; i < q; ++i) {
        cin >> y1 >> x1 >> y2 >> x2;
        y1 -= 2, x1 -= 2, --y2, --x2;
        
        int big = pre[y2][x2];
        int upper = 0;
        int left = 0;
        int small = 0;
        if (y1 < 0 && x1 < 0) {
            cout << big << '\n';
            continue;
        }
        if (y1 >= 0) upper = pre[y1][x2];
        if (x1 >= 0) left = pre[y2][x1];
        if (x1 >= 0 && y1 >= 0) small = pre[y1][x1];
        cout << big - upper - left + small << '\n';
    }

}