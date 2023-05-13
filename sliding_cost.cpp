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

    int leftSize = (k + 1) / 2;
    long long left = 0;
    long long right = 0;

    for (int i = 0; i < k; ++i) {
        if (stl.empty()) {
            stl.insert(x[i]);
            left += x[i];
            continue;
        }
        if (stl.size() == leftSize) {
            if (x[i] < *stl.rbegin()) {
                auto it = --stl.end();
                right += *it;
                str.insert(*it);
                left -= *it;
                stl.erase(it);
                left += x[i];
                stl.insert(x[i]);
            }
            else {
                right += x[i];
                str.insert(x[i]);
            }
        }
        else {
            left += x[i];
            stl.insert(x[i]);
        }

    }

    // median * leftSize - left + right - median * rightSize
    // equivalent to
    // median * (leftSize - rightSize) - left + right


    cout << (long long)*stl.rbegin() * ((int)stl.size() - (int)str.size()) - left + right << ' ';
    for (int i = k, l = 0; i < n; ++i, ++l) {
        if (stl.count(x[l])) {
            auto it = stl.find(x[l]);
            left -= x[l];
            stl.erase(it);
            if (str.empty() || x[i] <= *str.begin()) {
                left += x[i];
                stl.insert(x[i]);
            }
            else {
                left += *str.begin();
                stl.insert(*str.begin());
                right -= *str.begin();
                str.erase(str.begin());
                right += x[i];
                str.insert(x[i]);
            }
        }
        else {
            auto it = str.find(x[l]);
            right -= *it;
            str.erase(it);
            if (x[i] < *stl.rbegin()) {
                right += *stl.rbegin();
                str.insert(*stl.rbegin());
                left -= *(--stl.end());
                stl.erase(--stl.end());
                left += x[i];
                stl.insert(x[i]);
            }
            else {
                right += x[i];
                str.insert(x[i]);
            }
        }
        cout << (long long)*stl.rbegin() * ((int)stl.size() - (int)str.size()) - left + right << ' ';
    }
    cout << '\n';

}