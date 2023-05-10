#include <bits/stdc++.h>

using namespace std;


int main(void) {
    string s;
    cin >> s;
    int n = s.size();

    int res = 1;
    int curr = 1;
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i - 1]) ++curr;
        else curr = 1;
        res = max(res, curr);
    }
    cout << res << "\n";
}