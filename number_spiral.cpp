#include <bits/stdc++.h>

using namespace std;


int main(void) {
    int t;
    cin >> t;

    int y, x;
    while (t--) {
        cin >> y >> x;

        int band = max(y, x);
        // if in band 3, there are 2^2 number below this
        // even bands right to left
        // odd bands left to right

        // from left to top, which index is this?
        int index = x + (band - y);

        long long base = (band - 1) * (long long) (band - 1); 
        // how many numbers in a band?
        // band + band - 1
        if (band & 1) {
            cout << base + index << "\n";
        }
        else {
            cout << base + (2 * band - index) << "\n";
        }
    }
}

// band = 3
// y = 1, x = 3