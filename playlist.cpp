#include <bits/stdc++.h>

using namespace std;


int k[200010];

int main(void) {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) cin >> k[i];

    int l = 0;
    set<int> st;
    int res = 1;

    for (int i = 0; i < n; ++i) {
        while (st.count(k[i])) {
            st.erase(k[l++]);
        }
        st.insert(k[i]);
        res = max(res, (int) st.size());
    }
    cout << res << "\n";

}