#include <bits/stdc++.h>

using namespace std;


int x[200010];
long long pref[200010];


int main(void) {

    int n, a, b;
    cin >> n >> a >> b;

    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
        pref[i] = pref[i - 1] + x[i];
    }
    
    multiset<long long> prefs = {0};

    // prefs.size() needs to be <= b-a+1
    long long res = pref[a] - *prefs.begin();
    int ll = 0;
    int lr = 1;
    for (int i = a + 1; i <= n; ++i) {
        prefs.insert(pref[lr++]);
        if (prefs.size() > b - a + 1) {
            auto it = prefs.find(pref[ll++]);
            prefs.erase(it);
        }
        res = max(res, pref[i] - *prefs.begin());
    }

    cout << res << '\n';
    // check the subarray ending at i
    // check the potential lhs's
}
