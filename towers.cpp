#include <bits/stdc++.h>

using namespace std;


int main(void) {

    int n;
    cin >> n;

    // at each step, place the cube on the tower bigger than but closest to its size
    multiset<int> st;
    int k;
    for (int i = 0; i < n; ++i) {
        cin >> k;
        auto it = st.upper_bound(k);
        if (it == st.end()) {
            st.insert(k);
            continue;
        }
        st.erase(it);
        st.insert(k);
    }
    cout << st.size() << "\n";
}