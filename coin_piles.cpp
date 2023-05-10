#include <bits/stdc++.h>

using namespace std;

int a, b;

bool valid() {
    if ((2 * b - a) % 3 != 0) return false;
    if ((2 * a - b) % 3 != 0) return false;
    if (2 * b - a < 0) return false;
    if (2 * a - b < 0) return false;
    return true;
}


int main(void) {
    int t;
    cin >> t;

    while (t--) {
        cin >> a >> b;

        if (valid()) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}