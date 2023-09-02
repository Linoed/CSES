#include <bits/stdc++.h>
using namespace std;


int par[19][200010];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    for (int i = 2; i <= n; ++i) {
        cin >> par[0][i];
    }
    
    for (int i = 1; i < 19; ++i) {
        for (int j = 1; j <= n; ++j) {
            par[i][j] = par[i - 1][par[i - 1][j]];
        }
    }

    int x, k;
    for (int i = 0; i < q; ++i) {
        cin >> x >> k;
        int curr = x;
        int cnt = 0;
        while (k) {
            if (k & 1) curr = par[cnt][curr];
            k >>= 1;
            ++cnt;
        }
        cout << (curr == 0 ? -1 : curr) << '\n';
    }


}