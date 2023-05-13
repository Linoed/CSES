#include <bits/stdc++.h>

using namespace std;

int x[200010];

int main(void) {

    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    multiset<int> stl;
    multiset<int> str;

    for (int i = 0; i < n; ++i) cin >> x[i];


    // 4 -> 2
    // 3 -> 2

    int left = (k + 1) / 2;

    for (int i = 0; i < k; ++i) {
        if (stl.empty()) {
            stl.insert(x[i]);
            continue;
        }
        if (stl.size() == left) {
            if (x[i] < *stl.rbegin()) {
                auto it = --stl.end();
                str.insert(*it);
                stl.erase(it);
                stl.insert(x[i]);
            }
            else {
                str.insert(x[i]);
            }
        }
        else {
            stl.insert(x[i]);
        }

    }

    cout << *stl.rbegin() << ' ';
    for (int i = k, l = 0; i < n; ++i, ++l) {
        if (stl.count(x[l])) {
            auto it = stl.find(x[l]);
            stl.erase(it);
            if (str.empty() || x[i] <= *str.begin()) {
                stl.insert(x[i]);
            }
            else {
                stl.insert(*str.begin());
                str.erase(str.begin());
                str.insert(x[i]);
            }
        }
        else {
            auto it = str.find(x[l]);
            str.erase(it);
            if (x[i] < *stl.rbegin()) {
                str.insert(*stl.rbegin());
                stl.erase(--stl.end());
                stl.insert(x[i]);
            }
            else {
                str.insert(x[i]);
            }
        }
        cout << *stl.rbegin() << ' ';
    }
    cout << '\n';

}