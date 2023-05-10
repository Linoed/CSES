#include <bits/stdc++.h>


using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;
    multiset<int> st;

    int h;
    for (int i = 0; i < n; ++i) {
        cin >> h;
        st.insert(h);
    }

    int t;
    for (int i = 0; i < m; ++i) {
        cin >> t;
        auto it = st.upper_bound(t);
        if (it == st.begin()) {
            cout << "-1\n";
            continue;
        }
        it = prev(it);
        cout << *it << "\n";
        st.erase(it);
    }
}