#include <bits/stdc++.h>

using namespace std;

pair<int, int> a[5010];


int main(void) {

    int n, x;
    cin >> n >> x;


    int b;
    for (int i = 0; i < n; ++i) {
        cin >> b;
        a[i] = {b, i};
    }


    sort(a, a + n);

    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            int tar = x - a[j].first - a[i].first;
            int lo = j + 1;
            int hi = n - 1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (a[mid].first == tar) {
                    cout << a[i].second + 1 << " " << a[j].second + 1 << " " << a[mid].second + 1 << '\n';
                    return 0;
                }
                if (a[mid].first < tar) {
                    lo = mid + 1;
                }
                else {
                    hi = mid - 1;
                }
            }
        }
    }

    cout << "IMPOSSIBLE\n";

}