#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>


int main(void) {

    int n, k;
    cin >> n >> k;

    ordered_set st;

    for (int i = 1; i <= n; ++i) st.insert(i);

    int idx = k % n;
    while (true) {
        auto it = st.find_by_order(idx);
        cout << *it << " ";
        st.erase(it);
        if (st.empty()) break;
        idx = (idx + k) % (st.size());
    }
    cout << "\n";

}

// find_by_order
// order_of_key

