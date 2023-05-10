#include <bits/stdc++.h>

using namespace std;


int idx[200010];
int x[200010];

int main(void) {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) cin >> x[i];
    iota(idx, idx + n, 0);
    // gets the index of the shit in the order it needs to appear
    sort(idx, idx + n, [&](const int a, const int b) {
        return x[a] < x[b];
    });

    int res = 0;
    for (int i = 1; i < n; ++i) if (idx[i] < idx[i - 1]) ++res;

    // res is equal to number of decreasing adjacent pairs 

    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        --a;
        --b;

        // idx[num] is the current index of element num (0 indexed)
        // a, b are the indices in x
        int first = min(x[a], x[b]) - 1;
        int second = max(x[a], x[b]) - 1;

        // first, second are the indices in idx
        if (first - 1 >= 0 && idx[first] < idx[first - 1]) {
            --res;
        }
        if (first + 1 < n && idx[first + 1] < idx[first]) {
            --res;
        }
        if (second - 1 >= 0 && second - 1 != first && idx[second] < idx[second - 1]) {
            --res;
        }
        if (second + 1 < n && idx[second + 1] < idx[second]) --res;


        

        swap(x[a], x[b]);
        // swap(idx[first], idx[second]);
        swap(idx[first], idx[second]);
        // idx[first] = b;
        // idx[second] = a;
        
        if (first - 1 >= 0 && idx[first] < idx[first - 1]) ++res;
        if (first + 1 < n && idx[first + 1] < idx[first]) ++res;
        if (second - 1 >= 0 && second - 1 != first && idx[second] < idx[second - 1]) ++res;
        if (second + 1 < n && idx[second + 1] < idx[second]) ++res;

        cout << res + 1 << "\n";
    }

}