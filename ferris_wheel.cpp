#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n, x;
    cin >> n >> x;

    int p;
    multiset<int> st;
    for (int i = 0; i < n; ++i) {
        cin >> p;
        st.insert(p);
    }   

    int res = 0;
    while (!st.empty()) {
        auto it = st.begin();
        auto it2 = st.upper_bound(x - *it);
        if (it2 == st.begin()) {
            st.erase(it);
            ++res;
            continue;
        }
        it2 = prev(it2);
        if (it == it2) {
            st.erase(it);
            ++res;
            continue;
        }
        st.erase(it);
        st.erase(it2);
        ++res;
    }
    cout << res << "\n";
}