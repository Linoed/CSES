#include <bits/stdc++.h>
using namespace std;

const int maxn = 600010;

struct query {
    char a;
    int b, c;
};

int p[maxn];
int bit[maxn];

void add(int x, int v) {
    for (int i = x; i < maxn; i += (i & -i)) bit[i] += v;
}

int prefix(int x) {
    int res = 0;
    for (int i = x; i > 0; i -= (i & -i)) res += bit[i];
    return res;
}

int rangeQuery(int a, int b) {
    return prefix(b) - prefix(a - 1);
}

unordered_map<int, int> mp;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    set<int> st;

    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        st.insert(p[i]);
    }

    vector<query> queries(q);

    char a;
    int b, c;
    for (int i = 0; i < q; ++i) {
        cin >> a >> b >> c;
        queries[i] = {a, b, c};
        if (a == '!') st.insert(c);
        else {
            st.insert(b);
            st.insert(c);
        }
    }

    mp.reserve(st.size());
    int v = 1;
    for (auto x : st) mp[x] = v++;

    for (int i = 1; i <= n; ++i) {
        add(mp[p[i]], 1);
    }

    for (auto q : queries) {
        if (q.a == '?') {
            cout << rangeQuery(mp[q.b], mp[q.c]) << '\n';
        }
        else {
            add(mp[p[q.b]], -1);
            p[q.b] = q.c;
            add(mp[q.c], 1);
        }
    }

}