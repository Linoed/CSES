#include <bits/stdc++.h>

using namespace std;


int main(void) {
    int n;
    cin >> n;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end());

    long long res = 0;
    long long time = 0;
    for (auto& x : v) {
        time += x.first;
        res += (long long) x.second - time;
    }
    cout << res << '\n';
}