#include <bits/stdc++.h>

using namespace std;


int main(void) {

    int n;
    cin >> n;

    set<int> st;
    set<int> st1;

    int x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        auto it = st.lower_bound(x);
        if (it != st.end()) st.erase(it);
        st.insert(x);
    }

    cout << st.size() << '\n';

}