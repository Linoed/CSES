#include <bits/stdc++.h>

using namespace std;


string s;

int main(void) {
    cin >> s;

    map<char, int> mp;
    for (auto x : s) mp[x]++;

    bool odd = false;
    char oddC;

    for (auto x : mp) {
        auto k = x.first;
        auto v = x.second;
        if (v & 1) {
            if (odd) {
                cout << "NO SOLUTION\n";
                return 0;
            }
            oddC = k;
            odd = true;
        }
    }


    string res;
    for (auto x : mp) {
        auto k = x.first;
        auto v = x.second;
        for (int i = 0; i < v / 2; ++i) res += k;
    }
    
    
    string resBack = res;
    reverse(resBack.begin(), resBack.end());
    if (odd) res += oddC;
    res += resBack;
    cout << res << "\n";
}