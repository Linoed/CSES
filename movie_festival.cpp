#include <bits/stdc++.h>

using namespace std;


int main(void) {
    int n;
    cin >> n;

    int a, b;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        v[i] = {a, b};
    }

    sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second != b.second) return a.second < b.second;
        return a.first > b.first;
    });

    int end = -1;
    int res = 0;
    for (auto& x : v) {
        if (x.first >= end) {
            end = x.second;
            ++res;
        }
    }
    cout << res << "\n";
}
