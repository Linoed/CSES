#include <bits/stdc++.h>

using namespace std;

int bit[400010];

int prefix(int x) {
    int res = 0;
    for (int i = x; i > 0; i -= (i & -i)) res += bit[i];
    return res;
}

void add(int x, int val) {
    for (int i = x; i < 400010; i += (i & -i)) bit[i] += val;
}

int query(int l, int r) {
    return prefix(r) - prefix(l - 1);
}

int main(void) {
    unordered_map<int, int> mp;
    set<int> st;
    int n;
    cin >> n;

    vector<pair<pair<int, int>, int>> v(n);

    int a, b;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        v[i] = {{a, b}, i};
        st.insert(a);
        st.insert(b);
    }

    // coordinate compression
    int idx = 1;
    for (auto x : st) mp[x] = idx++;

    sort(v.begin(), v.end(), [&](const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
        if (a.first.first != b.first.first) return a.first.first < b.first.first;
        if (a.first.second != b.first.second) return a.first.second > b.first.second;
        return a.second < b.second;
    });

    vector<int> res1(n);
    vector<int> res2(n);

    for (int i = 0; i < n; ++i) add(mp[v[i].first.second], 1);
    // for tuple (x, y), query how many to the right have RHS <= y?
    for (int i = 0; i < n; ++i) {
        add(mp[v[i].first.second], -1);
        int ans = query(1, mp[v[i].first.second]);
        res1[v[i].second] = ans;
    }

    memset(bit, 0, sizeof(bit));

    // for tuple (x, y), query how many to the left have RHS >= y?
    add(mp[v[0].first.second], 1);
    for (int i = 1; i < n; ++i) {
        int ans = query(mp[v[i].first.second], idx);
        res2[v[i].second] = ans;
        add(mp[v[i].first.second], 1);
    }
    for (auto x : res1) cout << x << " ";
    cout << "\n";
    for (auto x : res2) cout << x << " ";
    cout << "\n";

}