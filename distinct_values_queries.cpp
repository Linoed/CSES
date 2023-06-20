#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
const int block_size = 450;

struct query {
    int a, b, block, idx;

    query(void) {

    }

    query(int _a, int _b, int _block, int _idx) {
        a = _a;
        b = _b;
        block = _block;
        idx = _idx;
    }
};

int x[maxn];
int cnt[maxn];
int ans[maxn];
query queries[maxn];

map<int, int> mp;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    // coordinate compression
    int order = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
        if (mp.count(x[i])) x[i] = mp[x[i]];
        else {
            mp[x[i]] = order;
            x[i] = order++;
        }
    }

    int a, b;
    for (int i = 0; i < q; ++i) {
        cin >> a >> b;
        queries[i] = query(a, b, a / block_size, i);
    }

    sort(queries, queries + q, [](const query& a, const query& b) {
        if (a.block != b.block) return a.block < b.block;
        return a.b < b.b;
    });

    int res = 1;
    int l = queries[0].a, r = queries[0].a;
    cnt[x[l]]++;

    // mo's algorithm
    for (int i = 0; i < q; ++i) {
        auto& qry = queries[i];

        while (l != qry.a || r != qry.b) {
            if (r > qry.b) {
                if (cnt[x[r]] == 1) --res;
                cnt[x[r--]]--;
            }
            if (r < qry.b) {
                if (!cnt[x[++r]]) ++res;
                cnt[x[r]]++;
            }
            if (l > qry.a) {
                if (!cnt[x[--l]]) ++res;
                cnt[x[l]]++;
            }
            if (l < qry.a) {
                if (cnt[x[l]] == 1) --res;
                cnt[x[l++]]--;
            }
        }

        ans[qry.idx] = res;
    }

    for (int i = 0; i < q; ++i) cout << ans[i] << '\n';
}
