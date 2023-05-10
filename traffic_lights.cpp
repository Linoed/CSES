#include <bits/stdc++.h>

using namespace std;


int main(void) {

    // needed in order to not tle
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int x, n;
    cin >> x >> n;

    multiset<int> mst = {x};
    set<int> st = {0, x};

    int p;
    for (int i = 0; i < n; ++i) {
        cin >> p;
        auto right = st.upper_bound(p);
        auto left = prev(right);
        auto it = mst.lower_bound(*right - *left);
        int leftPart = p - *left;
        int rightPart = *right - p;
        mst.erase(it);
        mst.insert(leftPart);
        mst.insert(rightPart);
        st.insert(p);
        cout << *mst.rbegin() << " ";
    }
    cout << "\n";

}