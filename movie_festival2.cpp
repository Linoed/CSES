#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i].first >> v[i].second;

    multiset<int> st;
    for (int i = 0; i < k; ++i) st.insert(0);

    sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second != b.second) return a.second < b.second;
        // check 
        return a.first < b.first;
    });

    int res = 0;

    for (auto& x : v) {
        auto it = st.upper_bound(x.first);
        if (it == st.begin()) continue;
        st.erase(--it);
        st.insert(x.second);
        ++res;
    }
    cout << res << '\n';
}