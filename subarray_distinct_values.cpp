#include <bits/stdc++.h>

using namespace std;

int x[200010];
int main(void) {

    int k, n;
    cin >> n >> k;

    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    int l = 0;
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        mp[x[i]]++;
        while (mp.size() > k) {
            mp[x[l]]--;
            if (mp[x[l]] == 0) mp.erase(x[l]);
            ++l;
        }
        res += i - l + 1;
    }
    cout << res << '\n';
}