#include <bits/stdc++.h>
using namespace std;

long long bit[200010];

long long query(int x) {
    long long res = 0;
    for (int i = x; i; i -= (i & -i)) res += bit[i];
    return res;
}

void add(int x, int v) {
    for (int i = x; i < 200010; i += (i & -i)) bit[i] += v;
}

void add(int a, int b, int v) {
    add(a, v);
    add(b + 1, -v);
}



int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    int x;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        add(i, i, x);
    }



    int a, b, c, d;
    for (int i = 0; i < q; ++i) {
        cin >> a >> b;
        if (a == 1) {
            cin >> c >> d;
            add(b, c, d);
        }
        else {
            cout << query(b) << '\n';
        }
    }

}