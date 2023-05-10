#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n, x;
    cin >> n >> x;

    map<int, int> mp;
    int a;
    for (int i = 1; i <= n; ++i) {
        cin >> a;
        if (mp.count(x - a)) {
            cout << mp[x - a] << " " << i << "\n";
            return 0;
        } 
        mp[a] = i;
    }

    cout << "IMPOSSIBLE\n";

}