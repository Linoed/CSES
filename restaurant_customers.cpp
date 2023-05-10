#include <bits/stdc++.h>

using namespace std;


int main(void) {
    int n;
    cin >> n;

    int a, b;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        v.push_back({a, 1});
        v.push_back({b, -1});
    }

    int res = 0;
    int num = 0;

    sort(v.begin(), v.end());
    for (auto x : v) {
        num += x.second;
        res = max(res, num);
    }
    cout << res << "\n";

}