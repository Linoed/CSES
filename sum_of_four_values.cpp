#include <bits/stdc++.h>

using namespace std;


int a[1010];


int main(void) {
    int n;
    int x;
    cin >> n >> x;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    unordered_map<int, pair<int, int>> mp;

    for (int i = 0; i < n - 1; ++i) {
        // check pairs that start with this index, this index hasnt been filled yet
        for (int j = i + 1; j < n; ++j) {
            if (mp.count(x - a[i] - a[j])) {
                cout << mp[x - a[i] - a[j]].first + 1 << ' ' << mp[x - a[i] - a[j]].second + 1 << ' ' << i + 1 << ' ' << j + 1 << '\n';
                return 0;
            }
        }

        // fill in pairs that end with this index
        for (int j = 0; j < i; ++j) {
            mp[a[i] + a[j]] = {j, i};
        }
    }

    cout << "IMPOSSIBLE\n";
}