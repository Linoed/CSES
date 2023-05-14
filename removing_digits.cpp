#include <bits/stdc++.h>

using namespace std;

bool vis[1000010];

int main(void) {

    int n;
    cin >> n;

    queue<int> q;
    q.push(n);
    vis[n] = true;

    int lvl = 0;

    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; ++i) {
            auto node = q.front();
            if (!node) {
                cout << lvl << '\n';
                return 0;
            }
            q.pop();
            int x = node;
            while (x) {
                if (!vis[node - x % 10]) {
                    q.push(node - x % 10);
                    vis[node - x % 10] = true;
                }
                x /= 10;
            }
        }
        ++lvl;
    }
    cout << lvl << '\n';
}