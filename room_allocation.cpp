#include <bits/stdc++.h>

using namespace std;

int main(void) {

    int n;
    cin >> n;


    vector<pair<int, int>> v;

    int a, b;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;

        v.push_back({a, i + 1});
        v.push_back({b, -(i + 1)});
    }

    sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first != b.first) return a.first < b.first;
        return a.second > b.second;
    });


    vector<int> res(n);

    // ++rooms, need new room, check set
    // if nothing in set, get highest room

    // set of available rooms
    set<int> st;


    int curr = 0;
    int rooms = 0;
    for (auto& x : v) {
        if (x.second > 0) {
            ++curr;
            rooms = max(rooms, curr);
            if (st.empty()) {
                res[x.second - 1] = curr;
            }
            else {
                res[x.second - 1] = *st.begin();
                st.erase(st.begin());
            }
        }
        else {
            --curr;
            st.insert(res[abs(x.second) - 1]);
        }
    }

    cout << rooms << "\n";
    for (auto x : res) cout << x << " ";
    cout << "\n";

}