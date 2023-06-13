#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int bit[maxn];
int x[maxn];

void add(int x) {
    for (int i = x; i < maxn; i += (i & -i)) bit[i]++;
}

void remove(int x) {
    for (int i = x; i < maxn; i += (i & -i)) bit[i]--;
}

int prefix(int x) {
    int res = 0;
    for (int i = x; i > 0; i -= (i & -i)) res += bit[i];
    return res;
}

// find the smallest index whose prefix sum is equal to num
int findI(int num) {
    int lo = 1;
    int hi = maxn;
    int res = hi;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (prefix(mid) >= num) {
            res = mid;
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }
    return res;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
        add(i);
    }

    int v;
    for (int i = 0; i < n; ++i) {
        cin >> v;
        int idx = findI(v);
        remove(idx);
        cout << x[idx] << ' ';
    }
    cout << '\n';
    // set of all the indices

    // index 3 in the real list is the third index left in the set
}